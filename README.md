# Use for Driver L298

> **Tính năng:**
> - Điều khiển Driver L298 với chỉ <u>4 chân tín hiệu</u>.
> - Control Driver L298 with only **4-wires**.
>
> **Yêu cầu:**
> - Cần dùng 2 chân có tính năng `PWM` để Driver điều khiển được tốc độ cho Motor.
>
> **Tương thích:**
> - Sử dụng được với board Uno Và Mega.
>
> **Mở rộng:**
> - Bạn vẫn có thể sử dụng với các bo mạch khác được IDE Arduino hỗ trợ. Chỉ cần chọn đúng các chân tính năng theo yêu cầu.
> - `IN2` và `IN3` phải có `PWM`!
>
> **Chú ý:**
> - Trong thư mục *"examples"*, ở phần *"CHECK AT COMPILE"* trong code mẫu, có chức năng kiểm tra các pin sử dụng có đúng không.
> - Đây là tính năng cho Trình Biên dịch kiểm tra, dùng cho bo Uno và Mega.
> - Bạn có thể xóa đoạn code này để tắt chức năng kiểm tra.

|Hàm|Chức năng|Chi tiết|Phạm vi|
|---|---------|--------|-------|
|go_forward(`speed`)|Điều khiển xe đi thẳng tới|- Motor bên Trái đi tới (+)<br>- Motor bên Phải đi tới (+)|`0 : +255`
|go_forward_left(`speed`)|Điều khiển xe đi thẳng, rẽ trái|- Motor bên Trái đi tới, chậm hơn 1/2 (+)<br>- Motor bên Phải đi tới (+)|`0 : +255`
|go_forward_right(`speed`)|Điều khiển xe đi thẳng, rẽ phải|- Motor bên Trái đi tới (+)<br>- Motor bên Phải đi tới, chậm hơn 1/2 (+)|`0 : +255`
|-|-|-|-|
|go_back(`speed`)|Điều khiển xe đi lùi|- Motor bên Trái đi lùi (-)<br>- Motor bên Phải đi lùi (-)|`0 : +255`
|go_back_left(`speed`)|Điều khiển xe đi lùi, rẽ trái|- Motor bên Trái đi lùi, chậm hơn 1/2 (-)<br>- Motor bên Phải đi lùi (-)|`0 : +255`
|go_back_right(`speed`)|Điều khiển xe đi lùi, rẽ phải|- Motor bên Trái đi lùi (-)<br>- Motor bên Phải đi lùi, chậm hơn 1/2 (-)|`0 : +255`
|-|-|-|-|
|rotate_left(`speed`)|Điều khiển xe xoay trái|- Motor bên Trái đi lùi (-)<br>- Motor bên Phải đi tới (+)|`0 : +255`
|rotate_right(`speed`)|Điều khiển xe xoay phải|- Motor bên Trái đi tới (+)<br>- Motor bên Phải đi lùi (-)|`0 : +255`
|-|-|-|-|
|go_custom(`speedLeft`, `speedRight`)|Điều khiển xe di chuyển (tùy chỉnh)|- Giá trị dương (+), bánh xe quay hướng đi tới<br>- Giá trị âm (-), bánh xe quay hướng đi lùi|`-255 : +255`
|stop()|Điều khiển dừng xe lại|- Dừng motor bên Trái<br>- Dừng motor bên Phải|*none*