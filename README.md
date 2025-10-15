# 🏦 ATM Console System (C++)

A simple **ATM simulation** built in **C++**, using file-based data storage (`Clients.txt`).  
The program allows users to log in, withdraw, deposit, and check their balance directly from the console.

---

## ✨ Features

- 🔐 **Login system** (Account Number + PIN)
- 💸 **Quick Withdraw** options (20–1000)
- 🧾 **Normal Withdraw** (custom amounts, multiples of 5)
- 💰 **Deposit** any positive amount
- 📊 **Check Balance**
- 💾 **Persistent Data Storage** in `Clients.txt`

---

## 🧠 How It Works

All client data is stored in a local text file (`Clients.txt`) in this format:

AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance


### Example:


1001#//#1234#//#Ali Ahmad#//#0501234567#//#1500
1002#//#5678#//#Sara Yusuf#//#0559876543#//#2300


Each client can log in using their **account number** and **PIN**, and then access the main ATM menu.

---

## 🖥️ Main Menu Options


============================================
ATM MAIN MENU SCREEN
 [1] Quick Withdraw
 [2] Normal Withdraw
 [3] Deposit
 [4] Check Balance
 [5] Logout


============================================
