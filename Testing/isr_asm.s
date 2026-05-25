    xdef    _vblisr
    xref    _do_vbl

_vblisr:    movem.l d0-d2/a0-a2,-(sp)
            jsr _do_vbl
            movem.l (sp)+,d0-d2/a0-a2
            rte