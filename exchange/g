	.text
	.file	"shift.c"
	.globl	shift_left4_rightn              # -- Begin function shift_left4_rightn
	.p2align	4, 0x90
	.type	shift_left4_rightn,@function
shift_left4_rightn:                     # @shift_left4_rightn
	.cfi_startproc
# %bb.0:
	movq	%rsi, %rcx
	movq	%rdi, %rax
	shlq	$4, %rax
                                        # kill: def $cl killed $cl killed $rcx
	sarq	%cl, %rax
	retq
.Lfunc_end0:
	.size	shift_left4_rightn, .Lfunc_end0-shift_left4_rightn
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 11.1.0"
	.section	".note.GNU-stack","",@progbits
	.addrsig
