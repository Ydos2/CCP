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
### Primitive ###
movl $999999, %eax
### ASSIGNMENT ###
### ARRAY ELEMENT ###
movl $0, %eax
pushl -4(%ebp,%ebx,4)
movl $97, %eax
movl %eax, -4(%ebp)
### ASSIGNMENT ###
### ARRAY ELEMENT ###
movl $1, %eax
pushl -4(%ebp,%ebx,4)
movl $98, %eax
movl %eax, -4(%ebp)
### ASSIGNMENT ###
### ARRAY ELEMENT ###
movl $2, %eax
pushl -4(%ebp,%ebx,4)
movl $99, %eax
movl %eax, -4(%ebp)
### ARRAY ELEMENT ###
movl $0, %eax
pushl -4(%ebp,%ebx,4)
### EPILOGUE ###
pop %edi
pop %esi
pop %ebx
leave
ret
