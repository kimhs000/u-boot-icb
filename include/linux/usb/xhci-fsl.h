/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright 2015 Freescale Semiconductor, Inc.
 *
 * FSL USB HOST xHCI Controller
 *
 * Author: Ramneek Mehresh<ramneek.mehresh@freescale.com>
 */

#ifndef _ASM_ARCH_XHCI_FSL_H_
#define _ASM_ARCH_XHCI_FSL_H_

/* Default to the FSL XHCI defines */
#define USB3_PWRCTL_CLK_CMD_MASK	0x3FE000
#define USB3_PWRCTL_CLK_FREQ_MASK	0xFFC
#define USB3_PHY_PARTIAL_RX_POWERON     BIT(6)
#define USB3_PHY_RX_POWERON		BIT(14)
#define USB3_PHY_TX_POWERON		BIT(15)
#define USB3_PHY_TX_RX_POWERON	(USB3_PHY_RX_POWERON | USB3_PHY_TX_POWERON)
#define USB3_PWRCTL_CLK_CMD_SHIFT   14
#define USB3_PWRCTL_CLK_FREQ_SHIFT	22
#define USB3_ENABLE_BEAT_BURST		0xF
#define USB3_ENABLE_BEAT_BURST_MASK	0xFF
#define USB3_SET_BEAT_BURST_LIMIT	0xF00

/* USBOTGSS_WRAPPER definitions */
#define USBOTGSS_WRAPRESET	BIT(17)
#define USBOTGSS_DMADISABLE BIT(16)
#define USBOTGSS_STANDBYMODE_NO_STANDBY BIT(4)
#define USBOTGSS_STANDBYMODE_SMRT		BIT(5)
#define USBOTGSS_STANDBYMODE_SMRT_WKUP (0x3 << 4)
#define USBOTGSS_IDLEMODE_NOIDLE BIT(2)
#define USBOTGSS_IDLEMODE_SMRT BIT(3)
#define USBOTGSS_IDLEMODE_SMRT_WKUP (0x3 << 2)

/* USBOTGSS_IRQENABLE_SET_0 bit */
#define USBOTGSS_COREIRQ_EN	BIT(1)

/* USBOTGSS_IRQENABLE_SET_1 bits */
#define USBOTGSS_IRQ_SET_1_IDPULLUP_FALL_EN	BIT(1)
#define USBOTGSS_IRQ_SET_1_DISCHRGVBUS_FALL_EN	BIT(3)
#define USBOTGSS_IRQ_SET_1_CHRGVBUS_FALL_EN	BIT(4)
#define USBOTGSS_IRQ_SET_1_DRVVBUS_FALL_EN	BIT(5)
#define USBOTGSS_IRQ_SET_1_IDPULLUP_RISE_EN	BIT(8)
#define USBOTGSS_IRQ_SET_1_DISCHRGVBUS_RISE_EN	BIT(11)
#define USBOTGSS_IRQ_SET_1_CHRGVBUS_RISE_EN	BIT(12)
#define USBOTGSS_IRQ_SET_1_DRVVBUS_RISE_EN	BIT(13)
#define USBOTGSS_IRQ_SET_1_OEVT_EN		BIT(16)
#define USBOTGSS_IRQ_SET_1_DMADISABLECLR_EN	BIT(17)

struct fsl_xhci {
	struct xhci_hccr *hcd;
	struct dwc3 *dwc3_reg;
};

#if defined(CONFIG_ARCH_LS1021A) || defined(CONFIG_ARCH_LS1012A)
#define CONFIG_SYS_FSL_XHCI_USB1_ADDR CONFIG_SYS_XHCI_USB1_ADDR
#define CONFIG_SYS_FSL_XHCI_USB2_ADDR 0
#define CONFIG_SYS_FSL_XHCI_USB3_ADDR 0
#elif defined(CONFIG_ARCH_LS2080A) || defined(CONFIG_ARCH_LS1088A)
#define CONFIG_SYS_FSL_XHCI_USB1_ADDR CONFIG_SYS_XHCI_USB1_ADDR
#define CONFIG_SYS_FSL_XHCI_USB2_ADDR CONFIG_SYS_XHCI_USB2_ADDR
#define CONFIG_SYS_FSL_XHCI_USB3_ADDR 0
#elif defined(CONFIG_ARCH_LS1043A) || defined(CONFIG_ARCH_LS1046A)
#define CONFIG_SYS_FSL_XHCI_USB1_ADDR CONFIG_SYS_XHCI_USB1_ADDR
#define CONFIG_SYS_FSL_XHCI_USB2_ADDR CONFIG_SYS_XHCI_USB2_ADDR
#define CONFIG_SYS_FSL_XHCI_USB3_ADDR CONFIG_SYS_XHCI_USB3_ADDR
#endif

#define FSL_USB_XHCI_ADDR	{CONFIG_SYS_FSL_XHCI_USB1_ADDR, \
					CONFIG_SYS_FSL_XHCI_USB2_ADDR, \
					CONFIG_SYS_FSL_XHCI_USB3_ADDR}
#endif /* _ASM_ARCH_XHCI_FSL_H_ */
