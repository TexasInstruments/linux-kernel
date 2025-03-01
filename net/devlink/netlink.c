// SPDX-License-Identifier: GPL-2.0-or-later
/*
 * Copyright (c) 2016 Mellanox Technologies. All rights reserved.
 * Copyright (c) 2016 Jiri Pirko <jiri@mellanox.com>
 */

#include <net/genetlink.h>
#include <net/sock.h>

#include "devl_internal.h"

static const struct genl_multicast_group devlink_nl_mcgrps[] = {
	[DEVLINK_MCGRP_CONFIG] = { .name = DEVLINK_GENL_MCGRP_CONFIG_NAME },
};

static const struct nla_policy devlink_nl_policy[DEVLINK_ATTR_MAX + 1] = {
	[DEVLINK_ATTR_UNSPEC] = { .strict_start_type =
		DEVLINK_ATTR_TRAP_POLICER_ID },
	[DEVLINK_ATTR_BUS_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_DEV_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_PORT_INDEX] = { .type = NLA_U32 },
	[DEVLINK_ATTR_PORT_TYPE] = NLA_POLICY_RANGE(NLA_U16, DEVLINK_PORT_TYPE_AUTO,
						    DEVLINK_PORT_TYPE_IB),
	[DEVLINK_ATTR_PORT_SPLIT_COUNT] = { .type = NLA_U32 },
	[DEVLINK_ATTR_SB_INDEX] = { .type = NLA_U32 },
	[DEVLINK_ATTR_SB_POOL_INDEX] = { .type = NLA_U16 },
	[DEVLINK_ATTR_SB_POOL_TYPE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_SB_POOL_SIZE] = { .type = NLA_U32 },
	[DEVLINK_ATTR_SB_POOL_THRESHOLD_TYPE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_SB_THRESHOLD] = { .type = NLA_U32 },
	[DEVLINK_ATTR_SB_TC_INDEX] = { .type = NLA_U16 },
	[DEVLINK_ATTR_ESWITCH_MODE] = NLA_POLICY_RANGE(NLA_U16, DEVLINK_ESWITCH_MODE_LEGACY,
						       DEVLINK_ESWITCH_MODE_SWITCHDEV),
	[DEVLINK_ATTR_ESWITCH_INLINE_MODE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_ESWITCH_ENCAP_MODE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_DPIPE_TABLE_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_DPIPE_TABLE_COUNTERS_ENABLED] = { .type = NLA_U8 },
	[DEVLINK_ATTR_RESOURCE_ID] = { .type = NLA_U64},
	[DEVLINK_ATTR_RESOURCE_SIZE] = { .type = NLA_U64},
	[DEVLINK_ATTR_PARAM_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_PARAM_TYPE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_PARAM_VALUE_CMODE] = { .type = NLA_U8 },
	[DEVLINK_ATTR_REGION_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_REGION_SNAPSHOT_ID] = { .type = NLA_U32 },
	[DEVLINK_ATTR_REGION_CHUNK_ADDR] = { .type = NLA_U64 },
	[DEVLINK_ATTR_REGION_CHUNK_LEN] = { .type = NLA_U64 },
	[DEVLINK_ATTR_HEALTH_REPORTER_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_HEALTH_REPORTER_GRACEFUL_PERIOD] = { .type = NLA_U64 },
	[DEVLINK_ATTR_HEALTH_REPORTER_AUTO_RECOVER] = { .type = NLA_U8 },
	[DEVLINK_ATTR_FLASH_UPDATE_FILE_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_FLASH_UPDATE_COMPONENT] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_FLASH_UPDATE_OVERWRITE_MASK] =
		NLA_POLICY_BITFIELD32(DEVLINK_SUPPORTED_FLASH_OVERWRITE_SECTIONS),
	[DEVLINK_ATTR_TRAP_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_TRAP_ACTION] = { .type = NLA_U8 },
	[DEVLINK_ATTR_TRAP_GROUP_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_NETNS_PID] = { .type = NLA_U32 },
	[DEVLINK_ATTR_NETNS_FD] = { .type = NLA_U32 },
	[DEVLINK_ATTR_NETNS_ID] = { .type = NLA_U32 },
	[DEVLINK_ATTR_HEALTH_REPORTER_AUTO_DUMP] = { .type = NLA_U8 },
	[DEVLINK_ATTR_TRAP_POLICER_ID] = { .type = NLA_U32 },
	[DEVLINK_ATTR_TRAP_POLICER_RATE] = { .type = NLA_U64 },
	[DEVLINK_ATTR_TRAP_POLICER_BURST] = { .type = NLA_U64 },
	[DEVLINK_ATTR_PORT_FUNCTION] = { .type = NLA_NESTED },
	[DEVLINK_ATTR_RELOAD_ACTION] = NLA_POLICY_RANGE(NLA_U8, DEVLINK_RELOAD_ACTION_DRIVER_REINIT,
							DEVLINK_RELOAD_ACTION_MAX),
	[DEVLINK_ATTR_RELOAD_LIMITS] = NLA_POLICY_BITFIELD32(DEVLINK_RELOAD_LIMITS_VALID_MASK),
	[DEVLINK_ATTR_PORT_FLAVOUR] = { .type = NLA_U16 },
	[DEVLINK_ATTR_PORT_PCI_PF_NUMBER] = { .type = NLA_U16 },
	[DEVLINK_ATTR_PORT_PCI_SF_NUMBER] = { .type = NLA_U32 },
	[DEVLINK_ATTR_PORT_CONTROLLER_NUMBER] = { .type = NLA_U32 },
	[DEVLINK_ATTR_RATE_TYPE] = { .type = NLA_U16 },
	[DEVLINK_ATTR_RATE_TX_SHARE] = { .type = NLA_U64 },
	[DEVLINK_ATTR_RATE_TX_MAX] = { .type = NLA_U64 },
	[DEVLINK_ATTR_RATE_NODE_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_RATE_PARENT_NODE_NAME] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_LINECARD_INDEX] = { .type = NLA_U32 },
	[DEVLINK_ATTR_LINECARD_TYPE] = { .type = NLA_NUL_STRING },
	[DEVLINK_ATTR_SELFTESTS] = { .type = NLA_NESTED },
	[DEVLINK_ATTR_RATE_TX_PRIORITY] = { .type = NLA_U32 },
	[DEVLINK_ATTR_RATE_TX_WEIGHT] = { .type = NLA_U32 },
	[DEVLINK_ATTR_REGION_DIRECT] = { .type = NLA_FLAG },
};

struct devlink *
devlink_get_from_attrs_lock(struct net *net, struct nlattr **attrs)
{
	struct devlink *devlink;
	unsigned long index;
	char *busname;
	char *devname;

	if (!attrs[DEVLINK_ATTR_BUS_NAME] || !attrs[DEVLINK_ATTR_DEV_NAME])
		return ERR_PTR(-EINVAL);

	busname = nla_data(attrs[DEVLINK_ATTR_BUS_NAME]);
	devname = nla_data(attrs[DEVLINK_ATTR_DEV_NAME]);

	devlinks_xa_for_each_registered_get(net, index, devlink) {
		devl_lock(devlink);
		if (devl_is_registered(devlink) &&
		    strcmp(devlink->dev->bus->name, busname) == 0 &&
		    strcmp(dev_name(devlink->dev), devname) == 0)
			return devlink;
		devl_unlock(devlink);
		devlink_put(devlink);
	}

	return ERR_PTR(-ENODEV);
}

static int __devlink_nl_pre_doit(struct sk_buff *skb, struct genl_info *info,
				 u8 flags)
{
	struct devlink_port *devlink_port;
	struct devlink *devlink;
	int err;

	devlink = devlink_get_from_attrs_lock(genl_info_net(info), info->attrs);
	if (IS_ERR(devlink))
		return PTR_ERR(devlink);

	info->user_ptr[0] = devlink;
	if (flags & DEVLINK_NL_FLAG_NEED_PORT) {
		devlink_port = devlink_port_get_from_info(devlink, info);
		if (IS_ERR(devlink_port)) {
			err = PTR_ERR(devlink_port);
			goto unlock;
		}
		info->user_ptr[1] = devlink_port;
	} else if (flags & DEVLINK_NL_FLAG_NEED_DEVLINK_OR_PORT) {
		devlink_port = devlink_port_get_from_info(devlink, info);
		if (!IS_ERR(devlink_port))
			info->user_ptr[1] = devlink_port;
	}
	return 0;

unlock:
	devl_unlock(devlink);
	devlink_put(devlink);
	return err;
}

int devlink_nl_pre_doit(const struct genl_split_ops *ops,
			struct sk_buff *skb, struct genl_info *info)
{
	return __devlink_nl_pre_doit(skb, info, ops->internal_flags);
}

int devlink_nl_pre_doit_port(const struct genl_split_ops *ops,
			     struct sk_buff *skb, struct genl_info *info)
{
	return __devlink_nl_pre_doit(skb, info, DEVLINK_NL_FLAG_NEED_PORT);
}

int devlink_nl_pre_doit_port_optional(const struct genl_split_ops *ops,
				      struct sk_buff *skb,
				      struct genl_info *info)
{
	return __devlink_nl_pre_doit(skb, info, DEVLINK_NL_FLAG_NEED_DEVLINK_OR_PORT);
}

void devlink_nl_post_doit(const struct genl_split_ops *ops,
			  struct sk_buff *skb, struct genl_info *info)
{
	struct devlink *devlink;

	devlink = info->user_ptr[0];
	devl_unlock(devlink);
	devlink_put(devlink);
}

static int devlink_nl_inst_single_dumpit(struct sk_buff *msg,
					 struct netlink_callback *cb, int flags,
					 devlink_nl_dump_one_func_t *dump_one,
					 struct nlattr **attrs)
{
	struct devlink *devlink;
	int err;

	devlink = devlink_get_from_attrs_lock(sock_net(msg->sk), attrs);
	if (IS_ERR(devlink))
		return PTR_ERR(devlink);
	err = dump_one(msg, devlink, cb, flags | NLM_F_DUMP_FILTERED);

	devl_unlock(devlink);
	devlink_put(devlink);

	if (err != -EMSGSIZE)
		return err;
	return msg->len;
}

static int devlink_nl_inst_iter_dumpit(struct sk_buff *msg,
				       struct netlink_callback *cb, int flags,
				       devlink_nl_dump_one_func_t *dump_one)
{
	struct devlink_nl_dump_state *state = devlink_dump_state(cb);
	struct devlink *devlink;
	int err = 0;

	while ((devlink = devlinks_xa_find_get(sock_net(msg->sk),
					       &state->instance))) {
		devl_lock(devlink);

		if (devl_is_registered(devlink))
			err = dump_one(msg, devlink, cb, flags);
		else
			err = 0;

		devl_unlock(devlink);
		devlink_put(devlink);

		if (err)
			break;

		state->instance++;

		/* restart sub-object walk for the next instance */
		state->idx = 0;
	}

	if (err != -EMSGSIZE)
		return err;
	return msg->len;
}

int devlink_nl_dumpit(struct sk_buff *msg, struct netlink_callback *cb,
		      devlink_nl_dump_one_func_t *dump_one)
{
	const struct genl_dumpit_info *info = genl_dumpit_info(cb);
	struct nlattr **attrs = info->attrs;
	int flags = NLM_F_MULTI;

	if (attrs &&
	    (attrs[DEVLINK_ATTR_BUS_NAME] || attrs[DEVLINK_ATTR_DEV_NAME]))
		return devlink_nl_inst_single_dumpit(msg, cb, flags, dump_one,
						     attrs);
	else
		return devlink_nl_inst_iter_dumpit(msg, cb, flags, dump_one);
}

struct genl_family devlink_nl_family __ro_after_init = {
	.name		= DEVLINK_GENL_NAME,
	.version	= DEVLINK_GENL_VERSION,
	.maxattr	= DEVLINK_ATTR_MAX,
	.policy		= devlink_nl_policy,
	.netnsok	= true,
	.parallel_ops	= true,
	.pre_doit	= devlink_nl_pre_doit,
	.post_doit	= devlink_nl_post_doit,
	.module		= THIS_MODULE,
	.small_ops	= devlink_nl_small_ops,
	.n_small_ops	= ARRAY_SIZE(devlink_nl_small_ops),
	.split_ops	= devlink_nl_ops,
	.n_split_ops	= ARRAY_SIZE(devlink_nl_ops),
	.resv_start_op	= DEVLINK_CMD_SELFTESTS_RUN + 1,
	.mcgrps		= devlink_nl_mcgrps,
	.n_mcgrps	= ARRAY_SIZE(devlink_nl_mcgrps),
};
