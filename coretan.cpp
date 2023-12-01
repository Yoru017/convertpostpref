#include <iostream>
#include <cstring>
using namespace std;

// Fungsi untuk menentukan prioritas operator
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Fungsi untuk mengubah ekspresi infix menjadi postfix
void infixToPostfix(char *infix, char *postfix)
{
    char s[100];  // array untuk menyimpan operator dan kurung
    int top = -1; // indeks teratas dari array s
    int i = 0;    // indeks untuk memindai ekspresi infix
    int j = 0;    // indeks untuk menyimpan ekspresi postfix
    while (infix[i] != '\0')
    { // selama ekspresi infix belum selesai dipindai
        if (isalnum(infix[i]))
        {                            // jika karakter adalah operand
            postfix[j++] = infix[i]; // tambahkan ke ekspresi postfix
        }
        else if (infix[i] == '(')
        {                        // jika karakter adalah kurung buka
            s[++top] = infix[i]; // masukkan ke array s
        }
        else if (infix[i] == ')')
        { // jika karakter adalah kurung tutup
            while (top != -1 && s[top] != '(')
            {                            // selama array s tidak kosong dan karakter teratas bukan kurung buka
                postfix[j++] = s[top--]; // keluarkan karakter dari array s dan tambahkan ke ekspresi postfix
            }
            top--; // kurangi indeks teratas dari array s dan buang kurung buka
        }
        else
        { // jika karakter adalah operator
            while (top != -1 && precedence(s[top]) >= precedence(infix[i]))
            {                            // selama array s tidak kosong dan operator teratas memiliki prioritas yang sama atau lebih tinggi dari karakter
                postfix[j++] = s[top--]; // keluarkan operator dari array s dan tambahkan ke ekspresi postfix
            }
            s[++top] = infix[i]; // masukkan karakter ke array s
        }
        i++; // tambah indeks untuk memindai ekspresi infix
    }
    while (top != -1)
    {                            // selama array s tidak kosong
        postfix[j++] = s[top--]; // keluarkan karakter dari array s dan tambahkan ke ekspresi postfix
    }
    postfix[j] = '\0'; // tambahkan karakter null di akhir ekspresi postfix
}

// Fungsi utama untuk menguji program
int main()
{
    char infix[100];   // array untuk menyimpan ekspresi infix
    char postfix[100]; // array untuk menyimpan ekspresi postfix
    cout << "Masukkan ekspresi infix: ";
    cin >> infix;                                    // baca ekspresi infix dari input pengguna
    infixToPostfix(infix, postfix);                  // ubah ekspresi infix menjadi postfix
    cout << "Ekspresi postfix: " << postfix << endl; // cetak ekspresi postfix
    return 0;
}