.data

.text

### PROLOGUE ###
####### OTHER FUNCTION #######
array:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
### ASSIGNMENT ###
movl %eax, -4(%ebp)
### ASSIGNMENT ###
movl $99, %eax
movl %eax, -4(%ebp)
call array
movl %eax, -0(%ebp)
movl $0, %eax
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
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
movl $5, %eax
movl %eax, -4(%ebp)

### IF NO ELSE ###

### Noteq ###
### GET ID ###
movl -4(%ebp), %eax
movl %eax, %ebx
movl $3, %eax
cmpl %ebx, %eax
jle JUMP1
### ASSIGNMENT ###
movl $7, %eax
movl %eax, -4(%ebp)
JUMP1:

### END IF NO ELSE ###


### IF ELSE ###

### Noteq ###
### GET ID ###
movl -4(%ebp), %eax
movl %eax, %ebx
movl $3, %eax
cmpl %ebx, %eax
jle JUMP2
### ASSIGNMENT ###
movl $9, %eax
movl %eax, -4(%ebp)
jmp JUMP_ELSE1
JUMP2:

### IF NO ELSE ###

### Compare ###
### GET ID ###
movl -52(%ebp), %eax
movl %eax, %ebx
movl $1, %eax
cmpl %ebx, %eax
jne JUMP3
### ASSIGNMENT ###
movl $12, %eax
movl %eax, -4(%ebp)
JUMP3:

### END IF NO ELSE ###

JUMP_ELSE1:

### END IF ELSE ###

movl %eax, -52(%ebp)
movl $0, %eax
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
### PROLOGUE ###
####### OTHER FUNCTION #######
f:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
### PROLOGUE ###
####### OTHER FUNCTION #######
nested:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
movl %eax, -52(%ebp)
movl $0, %eax
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
movl %eax, -52(%ebp)
movl $1, %eax
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
### PROLOGUE ###
####### OTHER FUNCTION #######
main:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
### PROLOGUE ###
####### OTHER FUNCTION #######
tain:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
movl %eax, -52(%ebp)

### OR ###
movl $0, %eax
movl %eax, %ecx
movl $1, %eax
movl %eax, %edx
or %ecx, %edx
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
movl %eax, -52(%ebp)
### Noteq ###

### PLUS ###
movl $2, %eax
movl %eax, %ebx

### TIMES ###
movl $2, %eax
movl %eax, %ebx
movl $4, %eax
imul %ebx, %eax
add %ebx, %eax
movl %eax, %ebx
movl $3, %eax
cmpl %ebx, %eax
jle JUMP3
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
### PROLOGUE ###
####### OTHER FUNCTION #######
main1:
push %ebp
mov %esp, %ebp
push %ebx
push %esi
push %edi
movl %eax, -52(%ebp)
### Noteq ###

### PLUS ###
movl $2, %eax
movl %eax, %ebx

### TIMES ###
movl $2, %eax
movl %eax, %ebx
movl $4, %eax
imul %ebx, %eax
add %ebx, %eax
movl %eax, %ebx
movl $3, %eax
cmpl %ebx, %eax
jle JUMP3
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
