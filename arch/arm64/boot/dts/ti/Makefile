# SPDX-License-Identifier: GPL-2.0
#
# Make file to build device tree binaries for boards based on
# Texas Instruments Inc processors
#
# Copyright (C) 2016-2021 Texas Instruments Incorporated - https://www.ti.com/
#
# Entries are grouped as per SoC present on the board. Groups are sorted
# alphabetically.

# Boards with AM62x SoC
dtb-$(CONFIG_ARCH_K3) += k3-am625-beagleplay.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-phyboard-lyra-rdk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-sk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-nonwifi-dahlia.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-nonwifi-dev.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-nonwifi-yavia.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-wifi-dahlia.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-wifi-dev.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-verdin-wifi-yavia.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am62-lp-sk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am625-sk-csi2-ov5640.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-am625-sk-csi2-tevi-ov5640.dtbo

# Boards with AM62Ax SoC
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk-csi2-imx219.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk-fusion.dtbo
k3-am62a7-sk-csi2-imx219-dtbs := k3-am62a7-sk.dtb k3-am62a7-sk-csi2-imx219.dtbo
k3-am62a7-sk-fusion-imx390-dtbs := k3-am62a7-sk.dtb \
				   k3-am62a7-sk-fusion.dtbo \
				   k3-fpdlink-imx390-rcm-0-0.dtbo
k3-am62a7-sk-fusion-ov2312-dtbs := k3-am62a7-sk.dtb \
				   k3-am62a7-sk-fusion.dtbo \
				   k3-fpdlink-ov2312-0-0.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk-csi2-imx219.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk-fusion-imx390.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am62a7-sk-fusion-ov2312.dtb

# Boards with AM64x SoC
dtb-$(CONFIG_ARCH_K3) += k3-am642-evm.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am642-phyboard-electra-rdk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am642-sk.dtb

# Boards with AM65x SoC
k3-am654-gp-evm-dtbs := k3-am654-base-board.dtb k3-am654-base-board-rocktech-rk101-panel.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-am6528-iot2050-basic.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am6528-iot2050-basic-pg2.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am6548-iot2050-advanced.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am6548-iot2050-advanced-m2.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am6548-iot2050-advanced-pg2.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am654-base-board.dtb
dtb-$(CONFIG_ARCH_K3) += k3-am654-gp-evm.dtb

# Boards with J7200 SoC
k3-j7200-evm-dtbs := k3-j7200-common-proc-board.dtb k3-j7200-evm-quad-port-eth-exp.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-j7200-evm.dtb

# Boards with J721e SoC
k3-j721e-evm-dtbs := k3-j721e-common-proc-board.dtb k3-j721e-evm-quad-port-eth-exp.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-j721e-beagleboneai64.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j721e-evm.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j721e-evm-csi2-ov5640.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-j721e-evm-fusion.dtbo

dtb-$(CONFIG_ARCH_K3) += k3-j721e-sk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j721e-sk-csi2-ov5640.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-j721e-sk-csi2-rpi-imx219.dtbo

# Boards with J721s2 SoC
dtb-$(CONFIG_ARCH_K3) += k3-am68-sk-base-board.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j721s2-common-proc-board.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j721s2-evm-csi2-ov5640.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-j721s2-evm-fusion.dtbo

# Boards with J784s4 SoC
dtb-$(CONFIG_ARCH_K3) += k3-am69-sk.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j784s4-evm.dtb
dtb-$(CONFIG_ARCH_K3) += k3-j784s4-evm-csi2-ov5640.dtbo

# FPDLink Sensors
dtb-$(CONFIG_ARCH_K3) += k3-fpdlink-imx390-rcm-0-0.dtbo \
			 k3-fpdlink-imx390-rcm-0-1.dtbo \
			 k3-fpdlink-imx390-rcm-0-2.dtbo \
			 k3-fpdlink-imx390-rcm-0-3.dtbo \
			 k3-fpdlink-imx390-rcm-1-0.dtbo \
			 k3-fpdlink-imx390-rcm-1-1.dtbo \
			 k3-fpdlink-imx390-rcm-1-2.dtbo \
			 k3-fpdlink-imx390-rcm-1-3.dtbo
dtb-$(CONFIG_ARCH_K3) += k3-fpdlink-ov2312-0-0.dtbo \
			 k3-fpdlink-ov2312-0-1.dtbo \
			 k3-fpdlink-ov2312-0-2.dtbo \
			 k3-fpdlink-ov2312-0-3.dtbo

# Enable support for device-tree overlays
DTC_FLAGS_k3-am62-lp-sk += -@
DTC_FLAGS_k3-am625-sk += -@
DTC_FLAGS_k3-am625-sk-lpmdemo += -@
DTC_FLAGS_k3-am62a7-sk += -@
DTC_FLAGS_k3-am62a7-sk-fusion += -@
DTC_FLAGS_k3-am654-base-board += -@
DTC_FLAGS_k3-am6548-iot2050-advanced-m2 += -@
DTC_FLAGS_k3-j7200-common-proc-board += -@
DTC_FLAGS_k3-j721e-common-proc-board += -@
DTC_FLAGS_k3-j721e-evm-fusion += -@
DTC_FLAGS_k3-j721e-sk += -@
DTC_FLAGS_k3-j721s2-common-proc-board += -@
DTC_FLAGS_k3-j721s2-evm-fusion += -@
DTC_FLAGS_k3-j784s4-evm += -@
