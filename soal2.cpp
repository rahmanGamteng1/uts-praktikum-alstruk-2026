#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK = 5;
string stackBuku[MAX_STACK];
int top = -1; 

bool isStackEmpty() { 
    return top == -1; 
}

bool isStackFull() { 
    return top == MAX_STACK - 1; 
}

void push(string judul) {
    if (isStackFull()) {
        cout << "[Stack] penuh  bang ga bisa nambah\"" << judul << "\" lagi." << endl;
    } else {
        top++;
        stackBuku[top] = judul;
        cout << "[Stack] Buku \"" << judul << "\" berhasil di-push ke tumpukan." << endl;
    }
}

void pop() {
    if (isStackEmpty()) {
        cout << "[Stack] gada yg bisa di pop" << endl;
    } else {
        cout << "[Stack] Buku \"" << stackBuku[top] << "\" di-pop dari tumpukan." << endl;
        top--; 
    }
}

void peekStack() {
    if (isStackEmpty()) {
        cout << "[Stack] Kosong! Gak ada buku di pucuk." << endl;
    } else {
        cout << "[Stack] Peek (Puncak dingin bos): \"" << stackBuku[top] << "\"" << endl;
    }
}

void tampilkanStack() {
    if (isStackEmpty()) {
        cout << "--- Isi Stack saat ini: KOSONG ---" << endl;
    } else {
        cout << "--- Isi Stack saat ini (atas ke bawah) ---" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i + 1 << ". " << stackBuku[i] << endl;
        }
    }
    cout << endl;
}

const int MAX_QUEUE = 5;
string queueAntrian[MAX_QUEUE];
int front = -1;
int rear = -1;

bool isQueueEmpty() {
    return front == -1 || front > rear;
}

bool isQueueFull() {
    return rear == MAX_QUEUE - 1;
}

void enqueue(string nama) {
    if (isQueueFull()) {
        cout << "[Queue] Penuh, \"" << nama << "\" gak bisa masuk antrian." << endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        queueAntrian[rear] = nama;
        cout << "[Queue] \"" << nama << "\" berhasil masuk antrian" << endl;
    }
}

void dequeue() {
    if (isQueueEmpty()) {
        cout << "Kosong, gak ada yang bisa didequeue." << endl;
    } else {
        cout << "[Queue] \"" << queueAntrian[front] << "\" Selesai dilayani" << endl;
        front++;
        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void peekQueue() {
    if (isQueueEmpty()) {
        cout << "Kosong!" << endl;
    } else {
        cout << "Antrian terdepan: \"" << queueAntrian[front] << "\"" << endl;
    }
}

void tampilkanQueue() {
    if (isQueueEmpty()) {
        cout << "--- Isi Queue saat ini: KOSONG ---" << endl;
    } else {
        cout << "--- Isi Queue saat ini (depan ke belakang) ---" << endl;
        for (int i = front; i <= rear; i++) {
            cout << "- " << queueAntrian[i] << endl;
        }
    }
    cout << endl;
}


int main() {
    cout << "  \nTumpukan Buku  " << endl;
    cout << "==========================================" << endl;
    
    push("Fisika Dasar");
    push("Kalkulus");
    push("Algoritma");
    push("Jaringan");
    cout << endl;

    peekStack();
    cout << endl;

    pop();
    pop();
    cout << endl;

    tampilkanStack();

    cout << "    Antrian Pinjam   " << endl;
    cout << "==========================================" << endl;

    enqueue("Reza");
    tampilkanQueue();
    
    enqueue("Mia");
    tampilkanQueue();
    
    enqueue("Hendra");
    tampilkanQueue();

    peekQueue();
    cout << endl;

    dequeue();
    tampilkanQueue();

    enqueue("Putri");
    tampilkanQueue();

    return 0;
}