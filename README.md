# Complier
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
+ Giai đoàn tiền xử lý (Pre-processor)
+ Giai đoạn dịch NNBC sang Asembly (Compiler)
+ Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
+ Giai đoạn liên kết (Linker)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/3f495174-6b9e-4150-94d1-a534fbd11454)

**1. Giai đoạn tiền xử lý – Preprocessor**
Giai đoạn này sẽ thực hiện:
+ Nhận mã nguồn
+ Xóa bỏ tất cả chú thích, comments của chương trình
+ Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý

	_Ví dụ_: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
	
**2. Công đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly**
+ Phân tích cú pháp (syntax) của mã nguồn NNBC
+ Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

**3. Công đoạn dịch Assembly**
+ Dich chương trình => Sang mã máy 0 và 1
+ Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.

**4. Giai đoạn Linker**
+ Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
+ Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
+ Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.

=> Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.
***
***
# Phân vùng nhớ
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/4852764e-2926-47d6-86d2-aadc7d29bc7f)

**1. Text:**
* Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
* Chứa khai báo hằng số trong chương trình (.rodata)

**2. Data:**
* Quyền truy cập là read-write.
* Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
* Được giải phóng khi kết thúc chương trình.

**3. Bss:**
* Quyền truy cập là read-write.
* Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
* Được giải phóng khi kết thúc chương trình.

**4. Stack:**
* Quyền truy cập là read-write.
* Được sử dụng cấp phát cho biến local, input parameter của hàm,…
* Sẽ được giải phóng khi ra khỏi block code/hàm

**5. Heap:**
* Quyền truy cập là read-write.
* Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
* Sẽ được giải phóng khi gọi hàm free,…

***:point_right: Stack và Heap ?***
* Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
* Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
* Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
* Kích thước vùng nhớ
> Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).

> Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.
* Đặc điểm vùng nhớ
> Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.

> Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

_Lưu ý:_ việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian.
* Vấn đề lỗi xảy ra đối với vùng nhớ
> Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...

_Ví dụ về tràn bộ nhớ Stack với hàm đệ quy vô hạn:_
```
int foo(int x){

   printf("De quy khong gioi han\n");
    
   return foo(x);
    
}
```
> Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).
Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.

_Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:_

`int *A = (int *)malloc(18446744073709551615);`
***
***
# Macro, Function, Inline

**1. Macro:**

* Được xử lý bởi preprocessor
* Thay thế đoạn code được khai báo macro vào bất cứ chỗ nào xuất hiện macro đó
* VD: #define SUM(a,b)     (a+b)
* Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

**2. Inline:**

* Được xử lý bởi compiler
* Được khai báo với từ khóa inline
* Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compile
	
**3. Function**

* Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình PC hiện tại vào stack; chuyển PC tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
* Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function)

**4. So sánh**

* Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
* Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
* Hàm bình thường phải tạo một function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
* Macro khiến code trở nên dài hơn rất nhiều so với bình thường nhưng thời gian chạy nhanh.
* Hàm inline cũng khiến code dài hơn, tuy nhiên nó làm giảm thời gian chạy chương trình
* Hàm bình thường sẽ phải gọi function call nên tốn thời gian hơn inline function nhưng code ngắn gọn hơn.
***
***
# Thao tác BIT
**1. AND: x=y & z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/4792bda0-11e7-42ab-be91-24f3913a14cb)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/d3561b69-3f42-43be-882b-4521d221ab60)

**2. NOT: x=~y**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/171570a9-e47e-426f-b767-936f07b3da5c)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/bb83e7dd-62e9-42b4-88a4-eacea3ede919)

**3. OR: x=y | z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/38cba77d-f2be-4fc5-b936-8c19f6652cd0)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/2bba2c0c-d39c-4349-94a0-59f17229c219)

**4. XOR: x = y ^ z**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/328b53db-f44c-4519-b35b-65275ce82205)
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/62261a3f-24f3-452b-b13d-4322da32269b)
  
**5. Dịch Bit: >> (Dịch phải) và << ( Dịch trái )**
 
![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/2e1f97a1-a4d2-4422-923c-546b76e0d9f7)
***
**:blue_square: Ví dụ: Giả sử có 1 vi điều khiển 8bit (1 lần quét điều khiển được 8 chân)**

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/e7d842d4-46ba-405e-885c-79b5e9e6ab99)
* Xây dựng thuật toán set mức cao thấp tại các chân pin:

> Thuật toán set mức cao: PORTA=0b00000000
```
    PORTA = PORTA |(0b10000000 >> pin);
```

=> Giả sử set chân PIN4 về mức cao thì pin=5, 0b10000000 dịch sang phải 5 bit là: 0b00001000 rồi thực hiện phép AND với PORTA thì cho kết quả là: 0b00001000 (chân PIN4 đã set về mức cao).
> Thuật toán set mức thấp: PORTA=0b11111111
```
    PORTA = PORTA & ~(0b10000000 >> pin); 
```

=> Giả sử set chân PIN3 về mức thấp thì pin=4, 0b10000000 dịch sang phải 4 bit là: 0b00010000, NOT của 0b00010000 là 0b11101111 rồi thực hiện phép OR với PORTA thì cho kết quả là: 0b11101111 (chân PIN3 đã set về mức thấp).
***
***
# Struct và union

Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:

* Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

* Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.
***
***
# Pointer

**:blue_square: Khái niệm con trỏ**
* Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích thước 1 byte.
* Mỗi ô nhớ có địa chỉ duy nhất và địa chỉ này được đánh số từ 0 trở đi. Nếu CPU 32 bit thì có 2^32 địa chỉ có thể đánh cho các ô nhớ trong RAM.

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/f787560d-631e-419e-a6bc-0724e36628c1)

* Khi khai báo biến, trình biên dịch dành riêng một vùng nhớ với địa chỉ duy nhất để lưu biến. Trình biên dịch có nhiệm vụ liên kết địa chỉ ô nhớ đó với tên biến. Khi gọi tên biến, nó sẽ truy xuất tự động đến ô nhớ đã liên kết với tên biến để lấy dữ liệu. Các bạn phải luôn phân biệt giữa địa chỉ bộ nhớ và dữ liệu được lưu trong đó.

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/83344433-7a60-4968-aa31-1cd15283555f)

* Địa chỉ của biến bản chất cũng là một con số thường được biểu diễn ở hệ cơ số 16. Ta có thể sử dụng con trỏ (pointer) để lưu địa chỉ của các biến.

**:blue_square: Con trỏ là gì?**

* Trong ngôn ngữ C/C++, con trỏ (pointer) là những biến lưu trữ địa chỉ bộ nhớ của những biến khác.

![image](https://github.com/hunggiao/Embedded-Interview/assets/133474779/aee473df-3636-43fd-ad0d-4407df5c47fd)

* Trong hình trên, biến var lưu giá trị 5 có địa chỉ là 0x61ff08. Biến pointVar là biến con trỏ, lưu địa chỉ của biến var (trỏ đến vùng nhớ của biến var), tức là nó lưu giá trị 0x61ff08.

**1. Con trỏ NULL:**

* Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.

```
int *p2;//con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ nào đó không xác định
int *p3 = NULL;//con trỏ null không trỏ đến vùng nhớ nào
```

**2. Con trỏ hàm:**

* Con trỏ hàm là con trỏ được tạo ra để lưu trữ địa chỉ của một hàm trong bộ nhớ máy tính.

* Một con trỏ hàm có thể khởi tạo theo mẫu sau:

<kiểu trả về> (*<tên con trỏ>)(<danh sách đối số>);

**3. Con trỏ void:**

* Con trỏ void là con trỏ có thể trỏ đến các vùng nhớ có các kiểu dữ liệu khác nhau

```
int n;
float f;
double d;

void *ptr;
ptr = &n; // ok
ptr = &f; // ok
ptr = &d; // ok
```

* Tuy nhiên, con trỏ void không xác định được kiểu dữ liệu của vùng nhớ mà nó trỏ tới. Vì vậy muốn truy cập xuất trực tiếp nội dung, ta cần ép kiểu cho con trỏ đó.

**4. Pointer to pointer:**

* Pointer to pointer là một loại con trỏ dùng để lưu trữ địa chỉ của biến con trỏ.
* Con trỏ trỏ đến con trỏ hoạt động như một con trỏ thông thường. Chúng ta có thể sử dụng toán tử dereference (*) để truy cập giá trị của con trỏ.

```
int main()	{

	int value = 100;
	int *ptr = &value;
	int **p_to_p = &ptr;

	pirntf("%p", p_to_p); //In ra địa chỉ của con trỏ ptr
	printf("%p", *p_to_p); //In ra địa chỉ mà con trỏ ptr đang trỏ đến (địa chỉ của biến value)
	printf("%d", **p_to_p); //In ra giá trị mà con trỏ ptr đang trỏ đến (giá trị của biến value)

	return 0;
}
```






