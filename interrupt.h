    
    .macro gie_disable
        setgie.d
        dsb
    .endm

    .macro gie_enable
        setgie.e
        dsb
    .endm

    .macro  SAVE_ALL
	pushm	$r0, $r5
	pushm	$r15,$r30
	mfsr    $r0, $PSW
	mfsr    $r1, $IPC
	mfsr    $r2, $IPSW
	pushm	$r0, $r2
	
	/* Descend interrupt level */
	/*bclr	$r0, $r0, #0x1*/
	li		$r3, 0xfffffffe
	and     $r0, $r0, $r3
	mtsr    $r0, $PSW
	dsb
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
	andi	$r1, $sp, #4
	subri	$r1, $r1, 4		! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
	push	$r2
    .endm

    .macro  RESTORE_ALL
	lwi	$sp, [$sp]
	popm    $r0, $r2
	mtsr    $r0, $PSW
	dsb
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW
	popm	$r15,$r30
	popm	$r0, $r5
   .endm

   .macro  SYSCALL_SAVE_ALL
	pushm	$r0, $r5
	pushm	$r15,$r30
	mfsr    $r0, $PSW
	mfsr    $r1, $IPC
	addi	$r1, $r1, 4
	mfsr    $r2, $IPSW
	pushm	$r0, $r2
	
	/* Descend interrupt level */
	/*bclr	$r0, $r0, #0x1*/
	li		$r3, 0xfffffffe
	and     $r0, $r0, $r3
	mtsr    $r0, $PSW
	dsb
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
	andi	$r1, $sp, #4
	subri	$r1, $r1, 4		! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
	push	$r2
   .endm

   .macro  SYSCALL_RESTORE_ALL
	lwi	$sp, [$sp]
	popm    $r0, $r2
	mtsr    $r0, $PSW
	dsb
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW
	popm	$r15,$r30
	addi	$sp, $sp, 4
	popm	$r1, $r5
   .endm

    .macro  SAVE_ALL_HW0
	pushm	$r0, $r5
	pushm	$r15,$r30
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
	andi	$r1, $sp, #4
	subri	$r1, $r1, 4		! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
	push	$r2
    .endm

    .macro  RESTORE_ALL_HW0
	lwi	$sp, [$sp]
	popm	$r15,$r30
	popm	$r0, $r5
   .endm

    .macro  SAVE_ALL_HW		!should not touch $r0
	/* push caller-saved gpr */
	pushm	$r1, $r5
	pushm	$r15, $r30
	
	/* push $INT_MASK */
	mfsr	$r1, $INT_MASK
	push	$r1		!push $INT_MASK

	/* disable low priority and 
	 * enable high priority interrupt */
	ori	$r1, $r1, 0x3f	! r1= {mask[31:6],000000}
	li	$r2, 1
	sll	$r2, $r2, $r0	! 1<<r0
	subri	$r2, $r2, 64	! 64 - (1 << r0)
	sub	$r1, $r1, $r2	! {mask[31:6],000000} - (64- (1<<r0))
	
	mtsr	$r1, $INT_MASK
	
	/* push $PSW, $IPC, $IPSW */
	mfsr    $r1, $PSW
	mfsr    $r2, $IPC
	mfsr    $r3, $IPSW
	pushm	$r1, $r3
	
	/* Descend interrupt level */
	/*bclr	$r1, $r1, #0x1*/
	li		$r3, 0xfffffffe
	and     $r0, $r0, $r3
	mtsr    $r1, $PSW
	
	gie_enable
	
	/* align $sp to 8B boundary */	
	move	$r2, $sp		!keep original $sp to be pushed
	andi	$r1, $sp, #4
	subri	$r1, $r1, 4		! bit2==0? 4 : 0
	sub	$sp, $sp, $r1		! bit2==0? (sp-=4) : (sp-=0)
	push	$r2
    .endm

    .macro  RESTORE_ALL_HW
	lwi	$sp, [$sp]

	/* pop $PSW, $IPC, $IPSW*/
	popm	$r0, $r2
	gie_disable
	mtsr    $r0, $PSW
	mtsr    $r1, $IPC
	mtsr    $r2, $IPSW

	/* pop $INT_MASK */
	pop	$r0		! get $INT_MASK
	mtsr	$r0, $INT_MASK	! restore $INT_MASK

	/* pop gpr */
	popm	$r15,$r30
	popm	$r1, $r5
	pop	$r0
   .endm
