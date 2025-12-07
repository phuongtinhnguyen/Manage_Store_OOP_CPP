QUẢN LÝ CỬA HÀNG
================
## Môi Trường
  1. Hệ điều hành: Window
  2. Phần mềm: Visual Studio Code.
  3. Extention: C/C++ extension for Visual Studio Code.
  4. Bộ biên dịch mã: GCC (GNU Compiler Collection) hay còn gọi là g++.

## Cài Đặt Trình Biên Dịch
Gợi ý cách cài đặt g++ (GCC) thông qua MSYS2.
  1. Cài đặt MSYS2. URL: https://www.msys2.org/
  2. Mở MSYS2 terminal window.
  3. Chạy command: pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
  4. Chấp nhận tất cả số lượng gói cài đặt mặc định trong công cụ bằng cách nhấn Enter.
  4. Thêm đường dẫn của MinGW-w64 bin folder vào Windows PATH environment variable.
    - Trong thanh tìm kiếm của Windows, nhập Settings để mở Windows Settings.
    - Tìm kiếm Edit environment variables for your account.
    - Trong User variables, chọn Path variable và chọn Edit.
    - Chọn New và thêm đường dẫn đến MinGW-w64 mà bạn đã ghi lại trong quá trình cài đặt vào danh sách.
    - Nếu bạn sử dụng các thiết lập mặc định, thì đường dẫn sẽ là: C:\msys64\ucrt64\bin
    - Thêm đường dẫn đó vào trong ô Edit evironment variable.
    - Chọn OK, rồi chọn OK một lần nữa trong cửa sổ Environment Variables để cập nhật biến môi trường PATH.
    - Để sử dụng được biến môi trường mới được thêm vào bạn phải mở lại tất cả các cửa sổ terminal hoặc powershell.
  5. Mở lại 1 powershell và chạy lệnh:
      gcc --version
      g++ --version
      gdb --version
    Kiểm tra output đảm bảo rằng các lệnh trên thành công. Nếu chưa thành công hãy kiểm tra lại biến môi trường.

## Hướng dẫn chi tiết từ Visual Studio Code
  https://code.visualstudio.com/docs/cpp/config-mingw

## Biên Dịch và Chạy:
  1. Vào thư mục chứa file main.cpp (<path/to/foder>/24880062/Source_code).
  2. Mở Visual Studio Code tiếp đến mở powershell trên Visual Studio Code (Ctrl + Shift + `).
  3. Chạy lệnh:
  ```
  g++ -o quanlycuahang main.cpp utils/LoaiHang.cpp utils/MatHang.cpp utils/HoaDon.cpp utils/HoaDonBan.cpp utils/HoaDonNhap.cpp utils/QuanLyLoaiHang.cpp utils/QuanLyMatHang.cpp utils/QuanLyHoaDon.cpp utils/Module.cpp
  ```
  4. File quanlycuahang.exe sẽ được biên dịch ra.
  5. Chạy: .\quanlycuahang.exe

## Cấu trúc project
```
|—— main.cpp
|—— README.md
|—— data
|    |—— hoadonban.csv
|    |—— hoadonnhap.csv
|    |—— loaihang.csv
|    |—— mathang.csv
|—— utils
|    |—— HoaDon.cpp
|    |—— HoaDon.h
|    |—— HoaDonBan.cpp
|    |—— HoaDonBan.h
|    |—— HoaDonNhap.cpp
|    |—— HoaDonNhap.h
|    |—— LoaiHang.cpp
|    |—— LoaiHang.h
|    |—— LoaiHoaDon.h
|    |—— MatHang.cpp
|    |—— MatHang.h
|    |—— Module.cpp
|    |—— Module.h
|    |—— QuanLyHoaDon.cpp
|    |—— QuanLyHoaDon.h
|    |—— QuanLyLoaiHang.cpp
|    |—— QuanLyLoaiHang.h
|    |—— QuanLyMatHang.cpp
|    |—— QuanLyMatHang.h
```

## Thông tin liên hệ
  Email sinh viên: 24880062@student.hcmus.edu.vn
  Email cá nhân: tinh.nguyen.ptn@gmail.com
  Số điện thoại: 0928497773
