	.text
	.file	"exchange.c"
	.globl	exchange                        # -- Begin function exchange
	.p2align	4, 0x90
	.type	exchange,@function
exchange:                               # @exchange
	.cfi_startproc
# %bb.0:
	movq	(%rdi), %rax
	movq	%rsi, (%rdi)
	retq
.Lfunc_end0:
	.size	exchange, .Lfunc_end0-exchange
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 11.1.0"
	.section	".note.GNU-stack","",@progbits
	.addrsig
