
# MachSoKhoaDienTu
Project Research from my team in Mat Ma Academy
    BAN CƠ YẾU CHÍNH PHỦ
HỌC VIỆN KĨ THUẬT MẬT MÃ






BÁO CÁO KẾT QUẢ
CHUYÊN ĐỀ NGHIÊN CỨU KHOA HỌC TRONG SINH VIÊN


MẠCH KHÓA SỐ ĐIỆN TỬ



Nhóm Trưởng: Hoàng Thanh Bình
Thành viên : Nguyễn Lưu Thành, Trần Văn Phong
Cán bộ hướng dẫn: Ths. Đặng Hùng Việt
Đơn vị công tác: Khoa điện tử - Viễn thông











Hà Nội, Ngày 04 tháng 04 năm 2018


MỤC LỤC
Lời nói đầu 	3
Chương 1. Sơ đồ và chức năng của mạch khóa số điện tử	4
1.1. Sơ đồ khối và chức năng của mạch khóa số điện tử	4
   1.2. Hoạt động của hệ thống	5
Chương 2. Thiết kế và thi công mạch	6
2.1. Sơ đồ và nguyên lý của mạch khóa số điện tử	6
2.2. Giới thiệu về PIC18F4550	6
2.3. Ghép nối LCD với PIC18F4550	12
2.4. Ghép nối ma trận phím với PIC18F4550	16
2.5. Ghép nối moudle sim800c với PIC18F4550	17
2.6. Mạch nguồn	20
2.7. Giới thiệu về Servo SG90	21
Chương 3. Thiết kế phần mềm	22
3.1 Lưu đồ thuật toán	22
3.2 Chương trình(Source Code)	24
Kết luận 	48
Tài liệu tham khảo 	49






DANH MỤC HÌNH VẼ
Hình 1.1 Sơ đồ khối của mạch khóa số điện tử……………………………..4
Hình 2.1 Sơ đồ nguyên lý của mạch khóa số điện tử…………...…………..6
Hình 2.2 Sơ đồ chân của PIC18F4550 trong hộp DIP-40…………………..7
Hình 2.3 Sơ đồ chân tín hiệu của LCD16x2……………………………….12
Hình 2.4 Sơ đồ kết nối LCD với PIC18F4550……...……………………..16
Hình 2.5 Sơ đồ ghép nối bàn phím với PIC18F4550…………...………....17
Hình 2.6 Sơ đồ ghép nối module sim800c với PIC18F4550……………....20
Hình 2.7 Sơ đồ mạch nguồn………………….……………………………20
Hình 3.1 Lưu đồ thuật toán điều khiển mạch khóa số điện tử……………..22

DANH MỤC BẢNG
Bảng 2.1 Chức năng của từng chân trong PIC18F4550………………….…8
Bảng 2.2 Chức năng các chân của LCD 16x2……………………………..12
Bảng 2.3 Tóm tắt các thiết lập đối với 2 chân RS và R/W của LCD…...…14
Bảng 2.4 Tập lệnh LCD…………………………………………………...15





LỜI NÓI ĐẦU
Ngày nay, với mỗi gia đình, cơ quan, trường học hay bất cứ nơi đâu, để bảo vệ tài sản trong phòng, trên mỗi cánh cửa ra vào đều được trang bị thêm chiếc khóa. Hiện nay, trên thị trường có rất nhiều loại khóa cửa nhưng hầu như đều là khóa cơ. Các loại khóa cơ này gặp vấn đề lớn là tính bảo mật của các loại khóa này không cao nên dễ bị phá khóa bởi các chìa khóa đa năng và cũng không thể mở khi mất chìa khóa.Vì vậy, để nâng cao yêu cầu tính bảo mật, giao diện dễ sử dụng, em chọn  “Khóa số điện tử” là đề tài nghiên cứu khoa học. 
Khóa số điện tử: Là hệ thống khóa nhỏ, gọn. Khóa được mở bằng mật mã do người dùng thiết lập. Ngoài ra khóa số điện tử có thể mở bằng các thiết bị điều khiển từ xa như điện thoại,…. Khóa số điện tử sử dụng màn hình LCD để hiển thị các thông báo về nhập mật khẩu, cảnh báo, thay đổi mật khẩu khiến người dùng dễ sử dụng hơn. Khóa có tính năng cảnh báo khi nhập sai mật khẩu nhiều lần liên tiếp.












CHƯƠNG 1. SƠ ĐỒ VÀ CHỨC NĂNG CỦA MẠCH KHÓA SỐ
1.1	Sơ đồ khối và chức năng của mạch khóa số
Sơ đồ khối của mạch khóa số, Hình 1.1














Hình 1.1. Sơ đồ khối của mạch khóa số
•	Khối nguồn: Có chức năng cung cấp điện áp cho mạch điện và vi điều khiển.
•	Khối điều khiển: 
o	Dùng PIC18F4550.
o	Có chức năng xử lý các thông tin, nhận thông tin từ bàn phím, đưa đến điều khiển động cơ và đưa thông tin hiển thị ra LCD thông báo cho người dùng. Lưu trữ mật khẩu qua bộ nhớ EEPROM có thể lưu trữ ngay khi mất điện.
•	Khối nhập dữ liệu:
o	Dùng bàn phím ma trận 4x4.
o	Thực hiện chức năng nhập dữ liệu đưa đến vi điều khiển.
•	Khối hiển thị:
o	Dùng LCD 16x2.
o	Có chức năng hiển thị thông tin cho người dùng.
•	Khối đóng mở cửa
o	Dùng động cơ SERVO SG90
o	Có chức năng đóng mở cửa
•	Khối điều khiển từ xa: 
o	Dùng Module sim800c.
o	Có chức năng giao tiếp với điện thoại để điều khiển từ xa.
1.2	 Hoạt động của hệ thống
•	Mở cửa: Có hai cách mở cửa:
o	Một là nhấn phím Unlock, hệ thống yêu cầu nhập mật khẩu. Nếu nhập đúng mật khẩu, động cơ sẽ quay để mở cửa và trên màn hình hiển thị thông báo cửa mở. Nếu nhập sai hệ thống yêu cầu nhập lại. Nếu nhập sai ba lần liên tiếp, hệ thống sẽ gửi cảnh báo về số điện thoại đã đăng kí và sẽ bị khóa,không hoạt động. Để hệ thống hoạt động lại, ta phải gửi lệnh cho hệ thống thông qua tin nhắn điện thoại.
o	Hai là gửi lệnh đã cài trước cho hệ thống thông qua tin nhắn điện thoại.
•	Khóa cửa: Nhấn phím Lock, động cơ sẽ quay để đóng cửa và trên màn hình hiển thị thông báo đóng cửa.
•	Đổi mật khẩu: Việc đổi mật khẩu chỉ thực hiện được khi cửa mở. Để đổi mật khẩu nhấn phím Change. Để an toàn, hệ thống sẽ yêu cầu nhập lại mật khẩu cũ. Nếu nhập đúng mật khẩu cũ, hệ thống sẽ yêu cầu nhập mật khẩu mới. Sau khi nhập mật khẩu mới, hệ thống sẽ yêu cầu xác nhận mật khẩu mới. Nếu khớp mật khẩu, mật khẩu được đổi và trên màn hình hiển thị thông báo đã đổi mật khẩu. Nếu không khớp mật khẩu, hệ thống sẽ yêu cầu nhập lại mật khẩu mới.
•	Lấy lại mật khẩu khi quên mật khẩu: Để lấy lại mật khẩu, ta gọi điện đến hệ thống. Hệ thống sẽ kiểm tra số điện thoại gọi đến. Nếu số điện thoại gọi đến là số điện thoại đã đăng kí thì hệ thống sẽ gửi mật khẩu về số điện thoại đã đăng kí.

 
CHƯƠNG 2. THIẾT KẾ VÀ THI CÔNG MẠCH
2.1 Sơ đồ nguyên lý của mạch khóa số điện tử
	Sơ đồ nguyên lý của mạch khóa số điện tử, Hình 2.1		 
Hình 2.1. Sơ đồ nguyên lý của mạch khóa số điện tử
2.2 Giới thiệu về PIC18F4550
•	Là một vi xử lý cơ bản đa chức năng. Nó là sản phẩm của họ vi xử lý PIC thông dụng của công ty Microchip của Mỹ có trụ sở đặt tại Chandler, Arizona (Mỹ).
•	Đặc điểm của PIC18F4550
o	Phạm vi điện áp hoạt động rộng (từ 2.0V đến 5.5V).
o	Bộ xử lý có thể hoạt động với tần số 48 MHz.
o	Có 32kb Flash lưu trữ chương trình, 2kb bộ nhớ SRAM và 256 byte EEPROM để lưu trữ dài hạn dữ liệu.
o	Có 5 Port và 35 pin I/O.
o	Có timer 8/16 bit.
o	Có các chuẩn giao tiếp nối tiếp đồng bộ/không đồng bộ USART.
o	Có các bộ chuyển đổi ADC.
o	Có các bộ so sánh điện áp (Voltage Comparators).
o	Có các khối Capture/Compare/PWM.
o	Có MSSP Peripheral dùng cho các giao tiếp I²C, SPI, và I²S.
o	Có bộ nhớ nội EEPROM - có thể ghi/xoá lên tới 1 triệu lần.
o	Có hỗ trợ giao tiếp USB.
•	Sơ đồ chân PIC184550 trong hộp DIP-40, Hình 2.2
 
Hình 2.2. Sơ đồ chân PIC184550 trong hộp DIP-40
•	Chức năng của từng chân trong PIC18F4550, Bảng 2.1
-	Chú thích:
		I : Đầu vào		O : Đầu ra		P : Cung cấp nguồn
Bảng 2.1. Chức năng của từng chân trong PIC18F4550
Chân	Kiểu	Chức năng
MCLR/VPP/RE3 
-	MCLR 
-	VPP 
-	RE3	
I
P
I	
-	Reset
-	Lập trình đầu vào điện áp
-	Đầu vào số
OSC1/CLKI 
-	OSC1 

-	CLKI	
I

I	-	Oscillator tinh thể đầu vào hoặc đồng hồ nguồn bên ngoài đầu vào
-	Ngõ vào đồng hồ bên ngoài. Luôn kết hợp với pin chức năng OSC1. (Xem ghim OSC2 / CLKO)
OSC2/CLKO/RA6 
-	OSC2 

-	CLKO 

-	RA6	
O

O

I/O	
-	Đầu ra tinh thể Oscillator. Kết nối với pha lê hoặc tiếng kêu vang trong chế độ Dao động Tinh thể
-	Trong chế độ RC, đầu ra pin OSC2 CLKO có 1/4 tần số của OSC1 và biểu thị chỉ dẫn tỷ lệ chu kỳ
-	Đầu vào/đầu ra mục đích chung 
RA0/AN0
-	RA0 
-	AN0	
I/O
I	
-	Xuất / nhập số - bit thứ 0 của Port A
-	Đầu vào tương tự 0
RA1/AN1
-	 RA1
-	 AN1	
I/O
I	
-	Xuất / nhập số - bit thứ 1 của Port A
-	Đầu vào tương tự 1
RA2/AN2/VREF-/CVREF
-	RA2 
-	AN2 
-	VREF
-	CVREF	

I/O
I
I
O	

-	Xuất / nhập số - bit thứ 2 của Port A
-	Đầu vào tương tự 2
-	Đầu vào điện áp chuẩn (thấp) của bộ ADC
-	Điện áp tham chiếu VREF, đầu vào bộ so sánh
RA3/AN3/VREF+
-	RA3
-	AN3
-	VREF+	
I/O
I
I	
-	Xuất / nhập số - bit thứ 3 của Port A
-	Đầu vào tương tự 3
-	Đầu vào điện áp chuẩn (cao) của bộ ADC
RA4/T0CKI/C1OUT/ RCV 
-	RA4
-	T0CKI 
-	C1OUT 
-	RCV	

I/O
I
O
I	

-	Xuất / nhập số - bit thứ 4 của Port A
-	Đầu vào đồng hồ Timer0
-	Đầu ra so sánh 1
-	Đầu vào bộ thu phát ngoài USB RCV
RA5/AN4/SS/ HLVDIN/C2OUT 
-	RA5
-	AN4 
-	SS 
-	HLVDIN 
-	C2OUT	

I/O
I
I
I
O	

-	Xuất / nhập số - bit thứ 5 của Port A
-	Đầu vào tương tự 4
-	SPI slave chọn đầu vào
-	Đầu vào phát hiện cao / thấp
-	Đầu ra so sánh 2
RB0/AN12/INT0/FLT0/ SDI/SDA 
-	RB0 
-	AN12 
-	INT0
-	 FLT0
-	 SDI
-	 SDA	

I/O
I
I
I
I
I/O	

-	Xuất / nhập số -bit thứ 0 của Port B 
-	Đầu vào tương tự 12
-	Đầu vào nhận tín hiệu ngắt ngoài 0 
-	Đầu vào lỗi PWM (module CCP1).
-	Dữ liệu SPI trong
-	Dữ liệu I / O 2C™.
RB1/AN10/INT1/SCK/ SCL 
-	RB1 
-	AN10 
-	INT1 
-	SCK 

-	SCL	

I/O
I
I
I/O

I/O	

-	Xuất / nhập số -bit thứ 1 của Port B 
-	Đầu vào tương tự 10
-	Đầu vào nhận tín hiệu ngắt ngoài 1
-	Đồng bộ nối tiếp đồng hồ đầu vào / đầu ra cho chế độ SPI
-	Đồng bộ nối tiếp đồng hồ đầu vào / đầu ra cho chế độ I2C
RB2/AN8/INT2/VMO 
-	RB2 
-	AN8 
-	INT2 
-	VMO	

I/O
I
I
O	

-	Xuất / nhập số -bit thứ 2 của Port B 
-	Đầu vào tương tự 8
-	Đầu vào nhận tín hiệu ngắt ngoài 2
-	Đầu ra máy thu phát ngoài VMO ngoài
RB3/AN9/CCP2/VPO
-	RB3 
-	AN9 
-	CCP2 

-	VPO	

I/O
I
I/O

O	

-	Xuất / nhập số -bit thứ 3 của Port B 
-	Đầu vào tương tự 9
-	Ngõ vào Capture 2 / So sánh 2 đầu ra / ngõ ra PWM2
-	Đầu ra VPO USB phát ngoài
RB4/AN11/KBI0/CSSPP 
-	RB4 
-	AN11 
-	KBI0 
-	CSSPP	

I/O
I
I
O	

-	Xuất / nhập số -bit thứ 4 của Port B 
-	Đầu vào tương tự 11
-	Ngắt khi thay pin 
-	SPP chip chọn đầu ra điều khiển-	
RB5/KBI1/PGM 
-	RB5 
-	KBI1 
-	PGM	
I/O
I
I/O	
-	Xuất / nhập số -bit thứ 5 của Port B
-	Ngắt khi thay pin 
-	Lập trình ICSP ™ với điện áp thấp cho phép pin
RB6/KBI2/PGC 
-	RB6 
-	KBI2 
-	PGC	
I/O
I
I/O	
-	Xuất / nhập số -bit thứ 6 của Port B
-	Ngắt khi thay pin 
-	Trình gỡ lỗi trong mạch và đồng hồ lập trình ICSP
RB7/KBI3/PGD 
-	RB7 
-	KBI3 
-	PGD	
I/O
I
I/O	
-	Xuất / nhập số -bit thứ 7 của Port B
-	Ngắt khi thay pin 
-	Trình gỡ lỗi trong mạch và mã dữ liệu lập trình ICSP
RC0/T1OSO/T13CKI 
-	RC0 
-	T1OSO 
-	T13CKI	

I/O
O
I	

-	Xuất / nhập số -bit thứ 0 của Port C
-	Timer1 Dao động đầu ra
-	Timer1 / Timer3 đầu vào đồng hồ bên ngoài
RC1/T1OSI/CCP2/ UOE 
-	RC1 
-	T1OSI 
-	CCP2 
-	UOE	

I/O
I
I/O
O	
-	Xuất / nhập số -bit thứ 1 của Port C
-	Đầu vào dao động Timer1
-	Ngõ vào Capture 2 / So sánh 2 đầu ra / ngõ ra PWM2
-	Đầu ra USB ngoài OE xuất
RC2/CCP1/P1A 
-	RC2 
-	CCP1 
-	
-	P1A	
I/O
I/O

O	
-	Xuất / nhập số -bit thứ 2 của Port C
-	Ngõ vào Capture 1 / So sánh 1 đầu ra / ngõ ra PWM1
-	Tăng cường đầu ra PWM CCP1, kênh A
RC4/D-/VM 
-	RC4
-	D-
-	VM	
I
I/O
I	
-	Nhập số -bit thứ 4 của Port C
-	USB phân đường trừ (đầu vào / đầu ra)
-	Đầu vào máy thu phát ngoài USB VM
RC5/D+/VP 
-	RC5 
-	D+ 
-	VP	
I
I/O
I	
-	Nhập số -bit thứ 5 của Port C
-	USB vi sai cộng với dòng (đầu vào / đầu ra)
-	Đầu vào máy thu phát ngoài USB VP
RC6/TX/CK 
-	RC6 
-	TX 
-	CK	
I/O
O
I/O	
-	Xuất / nhập số -bit thứ 6 của Port C
-	Truyền không đồng bộ EUSART
-	Đồng hồ đồng bộ EUSART (xem RX / DT)
RC7/RX/DT/SDO
-	RC7 
-	RX 
-	DT 
-	SDO	
I/O
I
I/O
O	
-	Xuất / nhập số -bit thứ 7 của Port C
-	Nhận không đồng bộ EUSART
-	Dữ liệu đồng bộ EUSART (xem TX / CK)
-	Dữ liệu ra SPI
RD0/SPP0 
-	RD0 
-	SPP0	
I/O
I/O	
-	Xuất / nhập số -bit thứ 0 của Port D
-	Dữ liệu cổng song song
RD1/SPP1 
-	RD1 
-	SPP1	
I/O
I/O	
-	Xuất / nhập số -bit thứ 1 của Port D
-	Dữ liệu cổng song song
RD2/SPP2 
-	RD2
-	SPP2	
I/O
I/O	
-	Xuất / nhập số -bit thứ 2 của Port D
-	Dữ liệu cổng song song
RD3/SPP3 
-	RD3 
-	SPP3	
I/O
I/O	
-	Xuất / nhập số -bit thứ 3 của Port D
-	Dữ liệu cổng song song
RD4/SPP4 
-	RD4 
-	SPP4	
I/O
I/O	
-	Xuất / nhập số -bit thứ 4 của Port D
-	Dữ liệu cổng song song
RD5/SPP5/P1B 
-	RD5 
-	SPP5 
-	P1B	
I/O
I/O
O	
-	Xuất / nhập số -bit thứ 5 của Port D
-	Dữ liệu cổng song song
-	Tăng cường đầu ra PWM CCP1, kênh B
RD6/SPP6/P1C 
-	RD6 
-	SPP6 
-	P1C 	
I/O
I/O
O	
-	Xuất / nhập số -bit thứ 6 của Port D
-	Dữ liệu cổng song song
-	Tăng cường đầu ra PWM CCP1, kênh C
RD7/SPP7/P1D 
-	RD7 
-	SPP7 
-	P1D	
I/O
I/O
O	
-	Xuất / nhập số -bit thứ 7 của Port D
-	Dữ liệu cổng song song
-	Tăng cường đầu ra PWM CCP1, kênh D
RE0/AN5/CK1SPP 
-	RE0 
-	AN5 
-	CK1SPP	
I/O
I
O	
-	Xuất / nhập số -bit thứ 0 của Port E 
-	Đầu vào tương tự 5
-	Đồng hồ SPP 1 đầu ra
RE1/AN6/CK2SPP 
-	RE1 
-	AN6 
-	CK2SPP	
I/O
I
O	
-	Xuất / nhập số -bit thứ 1 của Port E 
-	Đầu vào tương tự 6
-	Đồng hồ SPP 1 đầu ra
RE2/AN7/OESPP 
-	RE2 
-	AN7 
-	OESPP	
I/O
I
O	
-	Xuất / nhập số -bit thứ 2 của Port E 
-	Đầu vào tương tự 7
-	Đầu ra SPP cho phép xuất
VSS	P	-	Cung cấp nguồn âm
VDD	P	-	Cung cấp nguồn dương
VUSB	P	-	USB bên trong điều khiển điện áp 3.3V, cung cấp nguồn cho bộ thu phát USB

2.3 Ghép nối LCD với PIC18F4550
Sơ đồ chân tín hiệu của LCD 16x2, Hình 2.3
                          	     
				                LCD 16x2
Hình 2.3. Sơ đồ chân tín hiệu của LCD 16x2, Hình 2.3
•	Chức năng các chân của LCD16x2, Bảng 2.2
Bảng 2.2. Chức năng các chân của LCD16x2, Bảng 2.2
Chân số	Tên	Chức năng
1	VSS	Chân nối đất cho LCD, khi thiết kế mạch ta nối chân này với GND của mạch điều khiển
2	VDD	Chân cấp nguồn cho LCD, khi thiết kế mạch ta nối chân này với Vcc = 5V của mạch điều khiển
3	VEE	Chân này dùng để điều chỉnh độ tương phản của LCD


4	

RS	Chân chọn thanh ghi (Register select).
+ Logic “0”: Bus DB0-DB7 sẽ nối với thanh ghi lệnh IR của LCD (ở chế độ “ghi” - write) hoặc nối với bộ đếm địa chỉ của LCD (ở chế độ “đọc” - read)
+ Logic “1”: Bus DB0-DB7 sẽ nối với thanh ghi dữ liệu DR bên trong LCD.


5	

RW	Chân chọn chế độ đọc/ghi (Read/Write).  Nối chân R/W với logic “0” để LCD hoạt động ở chế độ ghi, hoặc nối với logic “1” để LCD ở chế độ đọc.






6	





E	Chân cho phép (Enable). Sau khi các tín hiệu được đặt lên bus DB0-DB7, các lệnh chỉ được chấp nhận khi có 1 xung cho phép của chân E. 
+ Ở chế độ ghi: Dữ liệu ở bus sẽ được LCD chuyển vào(chấp nhận) thanh ghi bên trong nó khi phát hiện một xung (high-to-low transition) của tín hiệu chân E.
+ Ở chế độ đọc: Dữ liệu sẽ được LCD xuất ra DB0-DB7 khi phát hiện cạnh lên (low- to-high transition) ở chân E và được LCD giữ ở bus đến khi nào chân E xuống mức thấp.



7-14	


DB0-DB7	Tám đường của bus dữ liệu dùng để trao đổi thông tin với MCU. Có 2 chế độ sử dụng 8 đường bus này :
+ Chế độ 8 bit : Dữ liệu được truyền trên cả 8 đường, với bit MSB là bit DB7.
+ Chế độ 4 bit : Dữ liệu được truyền trên 4 đường từ DB4 tới DB7, bit MSB là bit DB7.
15-16	A,K	Đèn của LCD

•	Cấu trúc của LCD16x2
o	Khi sản xuất LCD, nhà sản xuất đã tích hợp chíp điều khiển (HD44780) bên trong lớp vỏ và chỉ đưa các chân giao tiếp cần thiết. 
o	Chíp HD44780 có 2 thanh ghi 8 bit quan trọng:
+ Thanh ghi IR : Để điều khiển LCD, người dùng phải “ra lệnh” thông qua tám đường bus DB0-DB7. Mỗi lệnh được nhà sản xuất LCD đánh địa chỉ rõ ràng
Người dùng chỉ việc cung cấp địa chỉ lệnh bằng cách nạp vào thanh ghi IR. Nghĩa là, khi ta nạp vào thanh ghi IR một chuỗi 8 bit, chíp HD44780 sẽ tra bảng mã lệnh tại địa chỉ mà IR cung cấp và thực hiện lệnh đó. 
+ Thanh ghi DR : Thanh ghi DR dùng để chứa dữ liệu 8 bit để ghi vào vùng RAM 
DDRAM hoặc CGRAM (ở chế độ ghi) hoặc dùng để chứa dữ liệu từ 2 vùng RAM này gởi ra cho MPU (ở chế độ đọc). Nghĩa là, khi MPU ghi thông tin vào DR, mạch nội bên trong chíp sẽ tự động ghi thông tin này vào DDRAM hoặc CGRAM. Hoặc khi thông tin về địa chỉ được ghi vào IR, dữ liệu ở địa chỉ này trong vùng RAM nội của HD44780 sẽ được chuyển ra DR để truyền cho MCU. 
Bằng cách điều khiển chân RS và R/W chúng ta có thể chuyển qua lại giữa 2 thanh ghi này khi giao tiếp với MCU. Bảng 2.3 tóm tắt lại các thiết lập đối với hai chân RS và R/W theo mục đích giao tiếp:
Bảng 2.3. Tóm tắt các thiết lập đối với 2 chân RS và R/W của LCD
RS	RW	Khi cần
0	0	Ghi vào thanh ghi IR để ra lệnh cho LCD (VD: cần display clear,…)
0	1	Đọc cờ bận ở DB7 và giá trị của bộ đếm địa chỉ ở DB0-DB6
1	0	Ghi vào thanh ghi DR.
1	1	Đọc dữ liệu từ DR.
         
o	Cờ báo bận BF(Busy Flag):
Khi thực hiện các hoạt động bên trong chíp, mạch nội bên trong cần một khoảng thời gian để hoàn tất. Khi đang thực thi các hoạt động bên trong chip như thế, LCD bỏ qua mọi giao tiếp với bên ngoài và bật cờ BF (thông qua chân DB7 khi có thiết lập RS=0, R/W=1) lên để báo cho MPU biết nó đang “bận”. Dĩ nhiên, khi xong việc, nó sẽ đặt cờ BF lại mức 0. 
o	Bộ Đếm địa chỉ AC (Address Counter):
Thanh ghi IR không trực tiếp kết nối với vùng RAM (DDRAM và CGRAM) mà thông qua bộ đếm địa chỉ AC. Bộ đếm này lại nối với 2 vùng RAM theo kiểu rẽ nhánh. Khi một địa chỉ lệnh được nạp vào thanh ghi IR, thông tin được nối trực tiếp cho 2 vùng RAM nhưng việc chọn lựa vùng RAM tương tác đã được bao hàm trong mã lệnh.
o	Vùng Ram hiển thị DDRAM (Display Data RAM):
Đây là vùng RAM dùng để hiển thị, nghĩa là ứng với một địa chỉ của RAM là một ô kí tự trên màn hình và khi bạn ghi vào vùng RAM này một mã 8 bit, LCD sẽ hiển thị tại vị trí tương ứng trên màn hình một kí tự có mã 8 bit mà bạn đã cung cấp. 
Vùng RAM này có 80x8 bit nhớ, nghĩa là chứa được 80 kí tự mã 8 bit. Những vùng RAM còn lại không dùng cho hiển thị có thể dùng như vùng RAM đa mục đích. 
o	Vùng ROM chứa ký tự đồ họa:
Vùng ROM này dùng để chứa các mẫu kí tự loại 5x8 hoặc 5x10 điểm ảnh/kí tự, và định địa chỉ bằng 8 bit. Tuy nhiên, nó chỉ có 208 mẫu kí tự 5x8 và 32 mẫu kí tự kiểu 5x10 (tổng cộng là 240 thay vì 28  = 256 mẫu kí tự). Người dùng không thể thay đổi vùng ROM này.
o	Vùng RAM chứa kí tự đồ họa CGRAM  (Character Generator RAM):
Nhà sản xuất dành vùng có địa chỉ byte cao là 0000 để người dùng có thể tạo các mẫu kí tự đồ họa riêng. Tuy nhiên dung lượng vùng này rất hạn chế: Ta chỉ có thể tạo 8 kí tự loại 5x8 điểm ảnh, hoặc 4 kí tự loại 5x10 điểm ảnh. 
•	Tập lệnh của LCD, Bảng 2.4
Các lệnh của LCD có thể chia thành 4 nhóm như sau : 
-  Các lệnh về kiểu hiển thị. VD : Kiểu hiển thị (1 hàng / 2 hàng), chiều dài dữ liệu (8 bit / 4 bit), … 
-  Chỉ định địa chỉ RAM nội. 
-  Nhóm lệnh truyền dữ liệu trong RAM nội. 
-  Mã lệnh đến thanh ghi trong LCD:
Bảng 2.4. Tập lệnh LCD
Mã HEX	Lệnh đến đến thanh ghi của LCD
1	Xóa màn hình hiển thị
2	Trở về đầu dòng
4	Giảm con trỏ (Con trỏ dịch sang trái)
6	Tăng con trỏ (Con trỏ dịch sang phải)
5	Dịch hiển thị sang phải
7	Dịch hiển thị sang trái
8	Tắt con trỏ, tắt hiển thị
A	Tắt hiển thị bật con trỏ
C	Bật hiển thị, tắt con trỏ
E	Bật hiển thị, nhấp nháy con trỏ
F	Tắt con trỏ, nhấp nháy con trỏ
10	Dịch vị trí con trỏ sang trái
14	Dịch vị trí con trỏ sang phải
18	Dịch toàn bộ hiển thị sang trái
1C	Dịch toàn bộ hiển thị sang phải
80	Ép con trỏ về đầu dòng thứ nhất
C0	Ép con trỏ về đầu dòng thứ hai
38	Hai dòng và ma trận 5x7

•	Sơ đồ kết nối LCD với PIC18F4550, Hình 2.4

 
Hình 2.4. Sơ đồ kết nối LCD với PIC18F4550
2.4 Ghép nối ma trận phím với PIC18F4550
•	Sơ đồ ghép nối bàn phím với PIC18F4550, Hình 2.5
 
Hình 2.5. Sơ đồ ghép nối bàn phím với PIC18F4550
2.5 Ghép nối module sim800c với PIC18F4550
•	Tổng quan về module sim800c
o	Một modem GSM là một modem wireless, nó làm việc cùng với một mạng wireless GSM. Một modem wireless thì cũng hoạt động giông như một modem quay số. Điểm khác nhau chính ở đây là modem quay số thì truyền và nhận dữ liệu thông qua một đường dây điện thoại cố định trong khi đó một modem wireless thì việc gửi nhận dữ liệu thông qua sóng.
o	Giống như một điện thoại di động GSM, một modem GSM yêu cầu 1 thẻ sim với một mạng wireless để hoạt động.
o	Module sim800c là một trong những loại modem GSM. Nhưng Module sim800c được nâng cao hơn có tốc độ truyền dữ liệu nhanh hơn. Nó sử dụng công nghệ GSM/GPRS hoạt động ở băng tầng GSM 850Mhz, EGSM 900Mhz, DCS 1800 Mhz và PCS 1900Mhz, có tính năng GPRS của Sim 800
•	Đặc điểm của module sim800c
o	Nguồn cung cấp khoảng 3,4 – 4,5V.
o	Băng tần: GSM 850Mhz EGSM 900Mhz, DCS 1800 Mhz và PCS 1900Mhz SIM800c có thể tự động tìm kiếm các băng tần.
o	Giới hạn nhiệt độ:
	Bình thường: -300 độ C tới +800 độ C
	Hạn chế: -400 độ C tới -300 độ C và +800 độ C tới 850 độ C
o	SMS:
	MT, MO, CB, Text and PDU mode
	Bộ nhớ SMS: Sim card
o	Sim card:
	Hỗ trợ sim card : 1,8v ; 3v
o	Anten ngoài:
	Kết nối thông qua anten ngoài 500km
o	Times function:
	Lập trình thông qua AT command
•	Khảo sát tập lênh AT Command của Module sim800c
o	Các lệnh AT là các hướng dẫn được sử dụng để điều khiển một modem. AT là một cách viết gọn của chữ Attention. Mỗi dòng lệnh của nó bắt đầu với “AT” hay “at”. Đó là lý do tại sao các lệnh modem được gọi là các lệnh AT.
o	Các thuật ngữ :
<CR>: carriage return (0x0D).
<LF>: Line Feed (0x0A)
o	ATZ<CR><LF>: reset modem, kiểm tra modem đã hoạt động bình thường chưa.
o	ATE0<CR><LF> :tắt chế độ TE cho lệnh
o	AT+CLIP=1<CR> <LF>định dạng chuỗi trả về khi nhân cuộc gọi. Thông thường, ở chế độ mặc định, khi có cuộc gọi đến, chuỗi trả về sẽ có dạng :
<CR><LF>RING<CR><LF>
Sau khi lệnh AT+CLIP=1<CR> <LF>đã được thực thi, chuỗi trả về sẽ có dạng :
<CR><LF>RING<CR><LF>
<CR><LF>+CLIP:”0922050808”,129,””,,””,0,<CR><LF>
Chuỗi trả về có chứa thông tin về số điện thoại gọi đến. Thông tin này cho phép xác định việc có nên nhận cuộc gọi hay từ chối cuộc gọi.
o	AT&W<CR> <LF>Lưu cấu hình cài đặt được thiết bị bởi các tập lệnh AET0 và AT+CLIP vào bộ nhớ
o	AT+CMGF=1<CR><LF> Thiết lập quá trình truyền nhận tin nhắn được thực hiện ở chế độ text (mặc định là ở chế độ PDU) 
o	AT+CNMI=2,1<CR><LF>: Sau khi lệnh được thiết lập, tin nhắn mới nhận được sẽ được lưu trong sim
o	AT+CSAS<CR><LF>: Lưu cấu hình được thiết lập từ lệnh AT+CMGF và AT+CNMI
o	AT+CMGR=x<CR><LF>:Đọc tin nhắn ở vùng nhớ x
o	AT+CMGD=x<CR><LF>: Xóa tin nhắn vùng nhớ x trong SIM
o	AT+CMGFA=DEL ALL<CR><LF>: Xóa tất cả in nhắn trong SIM
o	ATDxxxxxxxxxxx;<CR><LF>: Thực hiện cuộc gọi
o	Gửi tin nhắn đến thuê bao bằng cách sử dụng lệnh AT+CMGS=”số điện thoại”.
			Nếu lệnh được thực hiện thành công, chuỗi trả về sẽ có dạng:
<CR><LF>> (kí tự “>” và 1 khoảng trắng).
			Gửi nội dung tin nhắn và kết thúc bằng kí tự có mã ASCII 0x1A.
Trên đây là một số lệnh em dùng để điều khiển Module sim800c. Ngoài những lệnh này, còn có rất nhiều lệnh điều khiển khác.
•	Sơ đồ ghép nối module sim800c với PIC18F4550, Hình 2.6
 
Hình 2.6. Sơ đồ ghép nối module sim800c với PIC18F4550
2.6 Mạch nguồn
Sơ đồ mạch nguồn, Hình 2.7
 
Hình 2.7. Sơ đồ mạch nguồn
 - Biến áp có tác dụng chuyển điện áp xoay chiều 220v thành điện áp xoay chiều 12v.
- Diode cầu có tác dụng chuyển điện áp xoay chiều 12v thành điện áp một chiều 12v
- Các tụ điện có tác dụng lọc dòng điện.
- IC7805 có tác dụng chuyển điện áp 12v thành điện áp 5v
2.7 Giới thiệu Servo SG90
Servo SG90 là một dạng động cơ điện đặc biệt. Không giống như động cơ thông thường cứ cắm điện vào là quay liên tục, servo chỉ quay khi được điều khiển (bằng xung PWM) với góc quay nằm trong khoảng bất kì từ 0o - 180o.
•	Thông số kĩ thuật Servo SG90
o	Khối lượng : 9g
o	Kích thước: 22.2x11.8.32 mm
o	Momen xoắn: 1.8kg/cm
o	Tốc độ hoạt động: 60 độ trong 0.1 giây
o	Điện áp hoạt động: 4.8V(~5V)
o	Nhiệt độ hoạt động: 0 ºC – 55 ºC
 
•	Điều khiển
Kết nối dây màu đỏ với 5V, dây màu nâu với mass, dây màu cam với chân phát xung của vi điều khiển. Ở chân xung cấp một xung từ 1ms-2ms để điều khiển góc quay theo ý muốn.
CHƯƠNG 3. THIẾT KẾ PHẦN MỀM
3.1	. Lưu đồ thuật toán
 	
	
                                                             
                                                                 
						 					 	
                                      
	
                                                                   	
	
                                                           
                                                                                                               
                                                                                                                                       
                                                 
                                                                                                                                  













	

























Hình 3.1.Lưu đồ thuật toán điều khiển khóa số điện tử
3.2 Chương trình ( Source code)
+ file main.c

#include <main.h>
#define LCD_ENABLE_PIN PIN_E2
#define LCD_RS_PIN PIN_E0
#define LCD_RW_PIN PIN_E1
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7
#include <lcd.c>
#include <keypad.h>
#include <string.h>
#include <stdio.h>

//Ban Phim
char Banphim[16]= {'1','4','7','*',
                   '2','5','8','0',
                   '3','6','9','#',
                   'a','b','c','d'};

int1 kt;
int8 key,mksai=0;
int8 NewSms=0,NewCall=0;
char Inpass[5],Newpass[5];
char Password[5];
char rcv=0,b1=0,b2=0,b3=0,b4=0,b5=0;
char Buffer[150];
int  o=0;
char SDT0[]="01683173311",SDT84[]="841683173311";
char PassUnlock[]="Lock";
char PassWarning[]="Seen";
int  counter=0,Servo=4;
//Ham kiem tra pass
int1 Ktmk(int1 b)
{
   Switch(b)
   {
      case 0: //Inpass vs Password
      {
         int8 a=0;
         for(int8 i=0;i<=4;i++)
         {
            if(Inpass[i]==Password[i])
            {
               a++;
            }
         }
         if(a==5) return 1;
         else return 0;
         break;
      }
      case 1: //Inpass vs Newpass
      {
         int8 a=0;
         for(int8 i=0;i<=4;i++)
         {
            if(Inpass[i]==Newpass[i])
            {
               a++;
            }
         }
         if(a==5) return 1;
         else return 0;
         break;
      }
   }
}
#int_RDA
void RDA_isr(void)
{
   rcv=getc();
   if(rcv=='+') b1=rcv;
   if(rcv=='C') b2=rcv;
   if(rcv=='M') b3=rcv;
   if(rcv=='T') b4=rcv;
   if(rcv=='I') b5=rcv;
   if(b1=='+' && b2=='C' && b3=='M' && b4=='T' && b5=='I')
   {
      NewSms=1;
   }
   //goi
   if(rcv=='+') b1=rcv;
   if(rcv=='C') b2=rcv;
   if(rcv=='L') b3=rcv;
   if(rcv=='I') b4=rcv;
   if(rcv=='P') b5=rcv;
   if(b1=='+' && b2=='C' && b3=='L' && b4=='I' && b5=='P')
   {
      NewCall=1;
   }
   //SMS,CALL
   if((NewSms==1 || NewCall==1) && rcv != '\0')
   {
      Buffer[o++]=rcv;
   }
   if(o>=150)
   {
      o=0;
   }
}
//Ngat timer
#INT_TIMER2
void  TIMER2_isr(void) 
{
   counter+=1;
   if(counter<=Servo)
   {
      set_pwm1_duty((int16)1021);
   }
   else if(counter>Servo && counter<=39)
   {
      set_pwm1_duty((int16)0);
   }
   else counter=0;
   
}
//Reset Buffer
void reset()
{
   NewSms=NewCall=0;
   b1=b2=b3=b4=b5=0;
   o=0;
   for(int i=0;i<=150;i++)
   {
      Buffer[i]='\0';
   }
   printf("AT+CMGDA=\"DEL ALL\"\r\n");
   delay_ms(500); 
}
void main()
{ 
   lcd_init();
   setup_timer_2(T2_DIV_BY_16,130,1);      //Cai dat timer
   setup_ccp1(CCP_PWM);                    //Cai dat CCP PWM
   set_pwm1_duty((int16)1021);
   enable_interrupts(INT_TIMER2);          //Ngat timer
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA); //cho phep ngat uart - ngat nhan du lieu tu sim800
   enable_interrupts(GLOBAL);
   for(int i=0;i<=4;i++)
   {
      Password[i]= read_eeprom(i);
      delay_ms(20);
   }
   Khoitaophim();
   Servo=4;
   counter=0;
   lcd_putc("Loading.....");
   delay_ms(12000);
   printf("AT+CNMI=2,1\r\n"); delay_ms(500);
   printf("AT+CSAS\r\n"); delay_ms(500);
   printf("AT+CMGS=\"01683173311\"\r\n");
   delay_ms(500);
   printf("Hello Bayby!");
   putc(26);
   delay_ms(500);
   lcd_putc("\f");
   lcd_gotoxy(4,1);
   lcd_putc("Welcome!!!");
   delay_ms(1000);
   int khoa=1;
GOTO4: lcd_putc("\f");
   lcd_gotoxy(5,1);
   lcd_putc("Locked!");
   while(true)
   {
      //Quen Mat Khau
      if(NewCall==1)                                //Neu co nguoi goi den
      {
         output_high(pin_a2);
         delay_ms(250);
         output_low(pin_a2);
         delay_ms(2000);
         printf("ATH\r\n"); delay_ms(500);
         if(strstr(Buffer,SDT0)!='\0'|| strstr(Buffer,SDT84)!='\0')
         {
            printf("AT+CMGS=\"%s\"\r\n",SDT0);
            delay_ms(500);
            printf("Mat khau: ");
            for(int i=0;i<=4;i++)
            {
               printf("%c",Password[i]);
            }
            putc(26);
            delay_ms(500);
         }
         reset();
      }
//Mo bang tin nhan
      if(NewSms==1)
      {
         output_high(pin_a2);
         delay_ms(250);
         output_low(pin_a2);
         printf("AT+CMGR=1\r\n"); 
         delay_ms(2000);
         if(strstr(Buffer,PassUnlock)!='\0')
         {
            khoa=0;
            mksai=0;
            output_high(pin_a0);
            reset();
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            delay_ms(150);
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            Servo=2;
            delay_ms(500);
            goto GOTO3;
         }
         reset();
      }
      
      
      key = QT();
      if(key==13&&khoa==1)                                            //Nhap MK
      {
GOTO5:   int8 index=6;
         int8 i=0;
         lcd_putc("\f");
         lcd_putc("Nhap Mat Khau:");
         lcd_gotoxy(6,2);
         lcd_putc("_____");
         while(i<=4)
         {
            key = QT();
            if(key==16)
            {
               goto GOTO4;
            }
            if((key>=1&&key<=3)||(key>=5&&key<=11))
            {
               Inpass[i]=Banphim[key-1];
               lcd_gotoxy(index,2);
               index++;
               printf(lcd_putc,"*");
               i++;
            }  
            delay_ms(50); 
         }
         delay_ms(250);
         kt=Ktmk(0);
         if(kt==1)
         {
            khoa=0;
            mksai=0;
            lcd_putc("\f");
            lcd_putc("Mat khau Dung!");
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            delay_ms(150);
            output_high(pin_a2);
            delay_ms(250);
            output_low(pin_a2);
            output_high(pin_a0);
            Servo=2;
            delay_ms(500);
    GOTO3:  lcd_putc("\f");
            lcd_gotoxy(5,1);
            lcd_putc("Unlocked!");
          }
          else if(kt==0)                        //Mat khau sai
          {
             mksai++;
             
             lcd_putc("\f");
             lcd_putc("Mat khau Sai!");
             output_high(pin_a2);
             delay_ms(500);
             output_low(pin_a2);
             if(mksai==3)
             {
                int ChinhChu=0;
                output_high(pin_a2);
                printf("AT+CMGS=\"%s\"\r\n",SDT0);
                delay_ms(500);
                printf("Canh Bao: Thiet bi da bi vo hieu hoa!");
                putc(26);
                delay_ms(500);
                printf(lcd_putc,"\f");
                lcd_gotoxy(4,1);
                printf(lcd_putc,"Warning!!!");
                output_high(pin_a1);
                while(ChinhChu==0)
                {
                  if(NewCall==1)
                  {
                     output_high(pin_a2);
                     delay_ms(250);
                     output_low(pin_a2);
                     delay_ms(1000);
                     printf("ATH\r\n"); delay_ms(500);
                     reset();
                  }
                  if(NewSms==1)
                  {
                     output_high(pin_a2);
                     delay_ms(250);
                     output_low(pin_a2);
                     printf("AT+CMGR=1\r\n"); 
                     delay_ms(2000);
                     if(strstr(Buffer,PassWarning)!='\0')
                     {
                        ChinhChu=1;
                     }
                     reset();
                  } 
                }
                mksai=0;
	     output_low(pin_a2);
                output_low(pin_a1);
             }
             delay_ms(750);
             lcd_putc("\f");
             lcd_putc("Moi Nhap Lai");
             delay_ms(750);
             goto GOTO5;
          }
      }
            
      if(key==14&&khoa==0)                                              // Khoa
      {
         khoa=1;
         output_high(pin_a2);
         delay_ms(500);
         output_low(pin_a2);
         output_low(pin_a0);
         Servo=4;
         delay_ms(500);
         lcd_putc("\f");
         lcd_gotoxy(5,1);
         lcd_putc("Locked!");
      }
      if(key==15&&khoa==0)                                            //Doi  mk
      {
    GOTO1: int8 index=6;                             //Nhap MK cu
           int8 i=0;
           lcd_putc("\f");                                  
           lcd_putc("Nhap MK cu:");
           lcd_gotoxy(6,2);
           lcd_putc("_____");
           while(i<=4)
           {
               key = QT();
               if(key==16)
               {
                  goto GOTO3;
               }
               if((key>=1&&key<=3)||(key>=5&&key<=11))
               {
                  Inpass[i]=Banphim[key-1];
                  lcd_gotoxy(index,2);
                  index++;
                  printf(lcd_putc,"*");
                  i++;
               }  
               delay_ms(50);
           }
           delay_ms(250);
           kt=ktmk(0);
           if(kt==1)
           {
              output_high(pin_a2);
              delay_ms(250);
              output_low(pin_a2);
              delay_ms(150);
              output_high(pin_a2);
              delay_ms(250);
              output_low(pin_a2);
     GOTO2:   lcd_putc("\f");                        //Nhap MK moi
              lcd_putc("Nhap MK moi:");
              lcd_gotoxy(6,2);
              lcd_putc("_____");
              int8 index=6;
              int8 i=0;
              while(i<=4)
              {
                 key = QT();
                 if(key==16)
                 {
                    goto GOTO3;
                 }
                 if((key>=1&&key<=3)||(key>=5&&key<=11))
                 {
                    Newpass[i]=Banphim[key-1];
                    lcd_gotoxy(index,2);
                    index++;
                    printf(lcd_putc,"*");
                    i++;
                 }
                 delay_ms(50);
              }
              delay_ms(250);
              lcd_putc("\f");                        //Kiem tra Mk moi
              lcd_putc("Xac nhan MK moi:");
              lcd_gotoxy(6,2);
              lcd_putc("_____");
              index=6;
              i=0;
              while(i<=4)
              {
                 key = QT();
                 if(key==16)
                 {
                    goto GOTO3;
                 }
                 if((key>=1&&key<=3)||(key>=5&&key<=11))
                 {
                     Inpass[i]=Banphim[key-1];
                     lcd_gotoxy(index,2);
                     index++;
                     printf(lcd_putc,"*");
                     i++;
                 }
                 delay_ms(50);
               }
               delay_ms(250);
               kt=Ktmk(1);
               if(kt==1)
               {
                   output_high(pin_a2);
                   delay_ms(250);
                   output_low(pin_a2);
                   delay_ms(150);
                   output_high(pin_a2);
                   delay_ms(250);
                   output_low(pin_a2);
                   lcd_putc("\f");
                   lcd_putc("Da doi mat khau!");
                   for(int8 i=0;i<=4;i++)
                   {
                       Password[i]=Newpass[i];
                       write_eeprom(i,Password[i]);
                       delay_ms(20);
                   }
                   delay_ms(750);
                   goto GOTO3;
                }
                else if(kt==0)
                {
                   output_high(pin_a2);
                   delay_ms(500);
                   output_low(pin_a2);
                   lcd_putc("\f");
                   lcd_putc("MK khong khop!");
                   delay_ms(750);
                   goto GOTO2;
                }   
           }
           else if(kt==0)
           {
               output_high(pin_a2);
               delay_ms(500);
               output_low(pin_a2);
               lcd_putc("\f");
               lcd_putc("Mat Khau Sai!");
               delay_ms(750);
               goto GOTO1;
           }
      }
      delay_ms(50);
   }
}

+ file main.h

#include <18F4550.h>
#device ADC=10

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#use delay(crystal=20000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
+ file Keypad.h

#define _keypad_h_
void Dieukhiencot(int8 cot,int1 trangthai);
void Khoitaophim(void);
int QT();

//Dinh nghia cot
#define C1 pin_b0
#define C2 pin_b1
#define C3 pin_b2
#define C4 pin_b3
//Dinh nghia  hang
#define H1 input(pin_b4)
#define H2 input(pin_b5)
#define H3 input(pin_b6)
#define H4 input(pin_b7)

//Ham dieu khien cot
void Dieukhiencot(int8 cot,int1 trangthai)
{
   switch(cot)
   {
      case 1:
      {
         output_bit(C1,trangthai);
         break;
      }
      case 2:
      {
         output_bit(C2,trangthai);
         break;
      }
      case 3:
      {
         output_bit(C3,trangthai);
         break;
      }
      case 4:
      {
         output_bit(C4,trangthai);
         break;
      }
   }
}
//Ham khoi tao ban phim
void Khoitaophim(void)
{
   for(int8 i=1;i<=4;i++)
   {
      Dieukhiencot(i,1);
   }
}
//Ham quet phim
int QT()
{
   int key=0;
//cot1
   Dieukhiencot(1,0);
   if(!H1)
   {
      while(!H1);
      key=1;
   }
   if(!H2)
   {
      while(!H2);
      key=2;
   }
   if(!H3)
   {
      while(!H3);   
      key=3;
   }
   if(!H4)
   {
      while(!H4);
      key=4;
   }
   Dieukhiencot(1,1);
//cot2
    Dieukhiencot(2,0);
   if(!H1)
   {
      while(!H1);
      key=5;
   }
   if(!H2)
   {
      while(!H2);
      key=6;
   }
   if(!H3)
   {
      while(!H3);
      key=7;
   }
   if(!H4)
   {
      while(!H4);
      key=8;
   }
   Dieukhiencot(2,1);
//cot3
    Dieukhiencot(3,0);
   if(!H1)
   {
      while(!H1); 
      key=9;
   }
   if(!H2)
   {
      while(!H2);
      key=10;
   }
   if(!H3)
   {
      while(!H3); 
      key=11;
   }
   if(!H4)
   {
      while(!H4);
      key=12;
   }
   Dieukhiencot(3,1);
//cot4
   Dieukhiencot(4,0);
   if(!H1)
   {
      while(!H1);
      key=13;
   }
   if(!H2)
   {
      while(!H2); 
      key=14;
   }
   if(!H3)
   {
      while(!H3); 
      key=15;
   }
   if(!H4)
   {
      while(!H4); 
      key=16;
   }
   Dieukhiencot(4,1);
   return key;
}
   
 


KẾT LUẬN
Sau thời gian nỗ lực thực hiện theo tiến độ, đề tài đã hoàn thành theo đúng mục tiêu đã đề ra.
Em xin trân thành cảm ơn sự hướng dẫn, giúp đỡ các thầy cô, bạn bè để nhóm hoàn thành nội dung đề tài theo đúng mục tiêu và tiến độ đặt ra.
Dù đã rất cố gắng, nhưng do thời gian có hạn và bước đầu thực hiện nghiên cứu, nên đề tài không tránh khỏi thiếu sót, mong nhận được sự góp ý của các thầy cô, bạn bè.

 


TÀI LIỆU THAM KHẢO
+ 123doc, “Giới thiệu cơ bản về LCD	16x2”
https://123doc.org/document/3564009-gioi-thieu-co-ban-ve-lcd-16x2.htm
+ Microchip, “PIC18F2455/2550/4455/4550 Data Sheet”
http://ww1.microchip.com/downloads/en/devicedoc/39632c.pdf
+ Mlab, “Hướng dẫn sử dụng module sim800c”
http://mlab.vn/14884-huong-dan-su-dung-module-sim800c.html
+ SIM COM, “SIM800 Series_AT Command Manual_V1.01”
https://cdnshop.adafruit.com/datasheets/sim800_series_at_command_manual_v1.01.pdf



   
   

