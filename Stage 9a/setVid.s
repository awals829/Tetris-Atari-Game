	xdef	_set_vid_base

base			equ	8

_set_vid_base:
	link	a6,#0
	movem.l	d0-2/a0-2,-(sp)
	move.l	base(a6),d0
	lsr.l	#8,d0
	lea		$FFFF8200,a0
	movep.w	d0,1(a0)
	movem.l	(sp)+,d0-2/a0-2
	unlk	a6
	rts