# 🏥 DỰ ÁN PBL2: HỆ THỐNG QUẢN LÝ BỆNH VIỆN & ĐƠN THUỐC 🚀

🛠️ **Ngôn ngữ:** `C++` &nbsp;|&nbsp; 💻 **Nền tảng:** `Windows` &nbsp;|&nbsp; 🎯 **Trạng thái:** `Hoàn thành (100%)`


> **Đồ án Cơ sở Lập trình (PBL2)**  
> Khoa Công nghệ Thông tin - Trường Đại học Bách Khoa - ĐHĐN.

---

## 📌 1. Giới thiệu dự án
Hệ thống hỗ trợ quản lý thông tin bệnh nhân, nhân viên, bác sĩ, cấp phát đơn thuốc và quản lý kho dược phẩm. Dự án được tối ưu hóa bằng cấu trúc dữ liệu hướng đối tượng (OOP) trong C++, giao diện bảng điều khiển trực quan, dễ sử dụng.

### 🌟 Tính năng nổi bật
* **Quản lý Nhân Sự:** Thêm, sửa, xóa, tìm kiếm thông tin chi tiết của Bác sĩ (`Doctor.h`), Nhân viên (`Nhanvien.h`), Y tá (`Yta.h`), và Bệnh nhân (`Patient.h`).
* **Xử lý Đơn Thuốc:** Quản lý danh mục thuốc (`Medicine.h`), tự động tính tiền và lưu trữ thông tin đơn thuốc (`DonThuoc.h`).
* **Hệ thống Đăng Nhập:** Phân quyền và bảo mật tài khoản cho các phiên làm việc (`Login.cpp`).
* **Lưu trữ dữ liệu:** Tự động đọc và ghi dữ liệu ra các file text trong hệ thống.

---

## 📂 2. Cấu trúc thư mục dự án
```text
├── 📄 main.cpp                 # File chạy chính của chương trình
├── 📄 Login.cpp                # Xử lý logic đăng nhập tài khoản
├── 📁 Headers (.h)
│   ├── Date.h                  # Quản lý cấu trúc ngày/tháng/năm
│   ├── Person.h                # Lớp cơ sở (Base class) thông tin con người
│   ├── Patient.h / Doctor.h    # Các lớp kế thừa quản lý Bệnh nhân, Bác sĩ
│   ├── Medicine.h / DonThuoc.h # Quản lý thông tin và hóa đơn thuốc
│   └── Manager_DonThuoc.h      # Điều phối và quản lý danh sách đơn thuốc
└── 📄 README.md                # Tài liệu hướng dẫn này
```

---

## 💻 3. Hướng dẫn Cài đặt & Chạy ứng dụng

### Yêu cầu hệ thống
* Máy tính đã cài đặt Trình biên dịch C++ (GCC/G++ hoặc MinGW).

### Thao tác chạy bằng dòng lệnh (Terminal)
1. Tải bản sao của dự án về máy tính:
   ```bash
   git clone https://github.com
   cd PBL2
   ```
2. Biên dịch mã nguồn:
   ```bash
   g++ main.cpp Login.cpp -o main
   ```
3. Khởi chạy ứng dụng:
   ```bash
   ./main
   ```

---

## 👥 4. Thành viên thực hiện

| STT | Họ và Tên | Mã số Sinh viên | Nhiệm vụ đảm nhiệm |
|---|---|---|---|
| 1 | **Phan Thanh Việt** | 102xxxxxx | Thiết kế Class, tối ưu hóa các hàm quản lý |
| 2 | **Trung** | 102xxxxxx | Xử lý logic File I/O, hoàn thiện giao diện |

---

## 📄 5. Giấy phép (License)
Dự án này được phát triển cho mục đích học tập tại trường ĐH Bách Khoa - ĐHĐN. Vui lòng ghi rõ nguồn nếu sử dụng lại tài liệu này.
