.data

.text

### PROLOGUE ###
####### MAIN FUNCTION #######
.globl Main
Main:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
### ASSIGNMENT ###
movl $2, %eax
movl %eax, -4(%ebp)
### ASSIGNMENT ###
movl $100, %eax
movl %eax, -20(%ebp)

### IF ELSE ###

### Compare ###
### GET ID ###
movl -4(%ebp), %eax
movl %eax, %ebx
movl $2, %eax
cmpl %ebx, %eax
jne JUMP1
### ASSIGNMENT ###
movl $100, %eax
movl %eax, -20(%ebp)
jmp JUMP_ELSE0
JUMP1:
### ASSIGNMENT ###
movl $97, %eax
movl %eax, -20(%ebp)
JUMP_ELSE0:

### END IF ELSE ###

### GET ID ###
movl -20(%ebp), %eax
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
