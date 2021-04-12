	.arch msp430g2553
	.p2align 1,0
	.text

	.global reset_assembly

reset_assembly:
	call #reset
