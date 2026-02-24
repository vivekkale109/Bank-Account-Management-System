# Bank Account Management System

## 📌 Project Description

The "Bank Account Management System" is a simple console-based application written in C.  
It allows users to perform basic banking operations such as:

- Deposit Money
- Withdraw Money
- Check Account Balance

All account data is stored permanently in a file using C file handling functions.

---

## 🚀 Features

- Deposit money into an account
- Withdraw money from an account
- Check account balance
- Data stored in a file for permanent storage
- Menu-driven interface
- Uses structures to store account details

---

## 🛠 Concepts Used

- C Structures (`struct`)
- File Handling:
  - `fopen()`
  - `fread()`
  - `fwrite()`
  - `fseek()`
  - `fclose()`
- `switch` statement
- `do-while` loop
- Conditional statements

---

## 📂 Project Structure

Bank-Account-Management/
│
├── bank.c → Main source code
├── bank.txt → Data file (created automatically)
└── README.md → Project documentation


---

## ▶️ How to Compile and Run

### Step 1: Compile
```bash
gcc bank.c -o bank
