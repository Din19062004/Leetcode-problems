#Assembly language
.data
    Message1: .asciiz  "Hay nhap 1 so nguyen duong N: "
    Message2: .asciiz  "Day khong phai la so nguyen duong\n"
    Message3: .asciiz  "Ket qua: "
    
.text
MAIN: li $v0, 4
      la $a0, Message1         #In ra Message1
      syscall 
    
      li   $v0, 5              #Nhap so nguyen duong N
      syscall 
      addi $s0, $v0, 0         #$s0 = N
    
      blez $s0, WRONGINPUT     #Neu N <= 0, dua ra thong bao va dung chuong trinh
      addi $a1, $zero, 1       #$a1 la output cua chuong trinh, gan bang 0
      addi $k0, $s0, 0         #Ban dau gan $k0 = N (dau vao cua chuong trinh con)
FOR:  jal  SUM                 #Goi chuong trinh con
      ble  $k1, 9, ENDFOR      #Neu $k1 <= 9 (tong cac chu so <= 9) thi dung vong lap
      addi $a1, $a1, 1         #$a1 = $a1 + 1
      addi $k0, $k1, 0         #$k0 (input) = $k1 (tong cac chu so neu > 9)
      j    FOR
ENDFOR:
      li   $v0, 4
      la   $a0, Message3       #In ra Message3
      syscall
      li   $v0, 1
      move $a0, $a1            #In ra output
      syscall
      li   $v0, 11
      li   $a0, '\n'           #In ky tu xuong dong
      syscall
      j    ENDMAIN             #Thoat khoi chuong trinh
    
WRONGINPUT: li $v0, 4
            la $a0, Message2   #In ra thong bao trong Message2
            syscall
            j  ENDMAIN         #Thoat khoi chuong trinh

ENDMAIN:    li $v0, 10
            syscall


#------------------------------------------------------------------------
#Chuong trinh con tinh tong cac chu so cua so nguyen duong X
#Dau vao: So nguyen duong X (luu trong $k0)
#Dau ra: Tong cua cac chu so trong X (luu trong $k1)
#------------------------------------------------------------------------
SUM:    addi $s1, $zero, 10    #$s1 = 10
        addi $k1, $zero, 0     #$k1 la tong cac chu so cua X
    
WHILE:  blez $k0, ENDWHILE     #Neu X <= 0 thi dung vong lap
        div  $k0, $s1          #Thuc hien phep chia X : 10, so du o trong thanh ghi $hi, thuong o trong thanh ghi $lo
        mfhi $t1               #$t1 la so du cua phep chia X : 10
        add  $k1, $k1, $t1     #cong tong cac chu so cua X
        mflo $t2               #$t2 la ket qua cua phep chia X : 10
        addi $k0, $t2, 0       #X = X : 10
        j    WHILE
ENDWHILE:
        jr   $ra               #Quay tro ve chuong trinh chinh
