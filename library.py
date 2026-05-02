import tkinter as tk
from tkinter import messagebox, ttk
import sqlite3

# Database setup
conn = sqlite3.connect('library.db')
cursor = conn.cursor()
cursor.execute('''
CREATE TABLE IF NOT EXISTS books (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    author TEXT NOT NULL,
    status TEXT NOT NULL
)
''')
conn.commit()

# Functions
def add_book():
    name = book_name.get()
    author = book_author.get()
    if name and author:
        cursor.execute('INSERT INTO books (name, author, status) VALUES (?, ?, ?)', (name, author, 'Available'))
        conn.commit()
        messagebox.showinfo('Success', 'Book Added')
        view_books()
    else:
        messagebox.showwarning('Warning', 'Fill all fields')

def view_books():
    for row in tree.get_children():
        tree.delete(row)
    cursor.execute('SELECT * FROM books')
    for row in cursor.fetchall():
        tree.insert('', tk.END, values=row)

def delete_book():
    selected = tree.focus()
    if selected:
        data = tree.item(selected)['values']
        cursor.execute('DELETE FROM books WHERE id=?', (data[0],))
        conn.commit()
        view_books()

# Login window
def login():
    if username.get() == 'admin' and password.get() == '1234':
        login_win.destroy()
        open_library()
    else:
        messagebox.showerror('Error', 'Invalid Login')

# Main app
def open_library():
    global book_name, book_author, tree
    app = tk.Tk()
    app.title('Library Management System')
    app.geometry('700x500')

    tk.Label(app, text='Book Name').pack()
    book_name = tk.Entry(app, width=40)
    book_name.pack()

    tk.Label(app, text='Author Name').pack()
    book_author = tk.Entry(app, width=40)
    book_author.pack()

    tk.Button(app, text='Add Book', command=add_book).pack(pady=5)
    tk.Button(app, text='Delete Book', command=delete_book).pack(pady=5)

    tree = ttk.Treeview(app, columns=('ID', 'Name', 'Author', 'Status'), show='headings')
    for col in ('ID', 'Name', 'Author', 'Status'):
        tree.heading(col, text=col)
    tree.pack(fill='both', expand=True, pady=10)

    view_books()
    app.mainloop()

login_win = tk.Tk()
login_win.title('Login')
login_win.geometry('300x200')

tk.Label(login_win, text='Username').pack(pady=5)
username = tk.Entry(login_win)
username.pack()

tk.Label(login_win, text='Password').pack(pady=5)
password = tk.Entry(login_win, show='*')
password.pack()

tk.Button(login_win, text='Login', command=login).pack(pady=20)

login_win.mainloop()
