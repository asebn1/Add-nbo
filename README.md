# Add-nbo

네트워크

32 bit 숫자가 파일에 4바이트의 크기로 저장되어 있다(network byte order). 2개의 파일을 입력받아 숫자를 읽어 들여 그 합을 출력하는 프로그램을 작성

실행
syntax : add-nbo <file1> <file2>
sample : add-nbo a.bin c.bin

# example
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
$ ./add-nbo thousand.bin five-hundred.bin
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)

![result](https://user-images.githubusercontent.com/57438644/87287056-98c15600-c534-11ea-8a46-190e196d5c0c.PNG)
