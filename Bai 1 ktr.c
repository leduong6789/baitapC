#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho một đơn thức
typedef struct Term {
    int coefficient; // Hệ số
    int exponent; // Số mũ
    struct Term* next; // Con trỏ đến đơn thức tiếp theo
} Term;

// Hàm tạo một đơn thức mới
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Hàm chèn một đơn thức vào đa thức
void insertTerm(Term** head, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*head == NULL || (*head)->exponent <= exponent) {
        newTerm->next = *head;
        *head = newTerm;
    } else {
        Term* temp = *head;
        while (temp->next != NULL && temp->next->exponent > exponent) {
            temp = temp->next;
        }
        newTerm->next = temp->next;
        temp->next = newTerm;
    }
}

// Hàm tìm đơn thức có hệ số nhỏ nhất
Term* findSmallestCoefficientTerm(Term* head) {
    if (head == NULL) return NULL;
    Term* smallest = head;
    Term* temp = head->next;
    while (temp != NULL) {
        if (temp->coefficient < smallest->coefficient) {
            smallest = temp;
        }
        temp = temp->next;
    }
    return smallest;
}

// Hàm in đa thức
void printPolynomial(Term* head) {
    Term* temp = head;
    while (temp != NULL) {
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) printf("+ ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Term* polynomial = NULL;

    // Chèn các đơn thức vào đa thức
    insertTerm(&polynomial, 4, 3);
    insertTerm(&polynomial, 3, 5);
    insertTerm(&polynomial, 5, 1);
    insertTerm(&polynomial, 1, 4);

    // In đa thức
    printf("Da thuc: ");
    printPolynomial(polynomial);

    // Tìm đơn thức có hệ số nhỏ nhất
    Term* smallestTerm = findSmallestCoefficientTerm(polynomial);
    if (smallestTerm != NULL) {
        printf("Don thuc co he so nho nhat: %dx^%d\n", smallestTerm->coefficient, smallestTerm->exponent);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Cấu trúc ngăn xếp (stack)
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack* s) {
    s->top = -1;
}

// Hàm kiểm tra ngăn xếp có rỗng không
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Hàm kiểm tra ngăn xếp có đầy không
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Hàm thêm một phần tử vào ngăn xếp
void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    }
}

// Hàm lấy một phần tử ra khỏi ngăn xếp
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return -1; // Trả về -1 nếu ngăn xếp rỗng
}

// Hàm lấy phần tử đầu ngăn xếp mà không lấy ra
int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return -1; // Trả về -1 nếu ngăn xếp rỗng
}

// Hàm xác định độ ưu tiên của toán tử
int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Hàm kiểm tra ký tự có phải là toán tử không
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Hàm chuyển đổi biểu thức infix sang postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    initStack(&s);
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Lấy dấu '(' ra khỏi ngăn xếp
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

// Hàm tính giá trị biểu thức postfix
int evaluatePostfix(char* postfix) {
    Stack s;
    initStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (isOperator(ch)) {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, val1 ^ val2); break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char infix[MAX] = "3+5*2/(7-2)";
    char postfix[MAX];

    // Chuyển đổi biểu thức infix sang postfix
    infixToPostfix(infix, postfix);

    printf("Bieu thuc postfix: %s\n", postfix);

    // Tính giá trị biểu thức postfix
    int result = evaluatePostfix(postfix);

    printf("Gia tri bieu thuc: %d\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Cấu trúc của một nút trong cây
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo một nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm chèn một phần tử vào cây BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trước (NLR)
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Hàm duyệt cây theo thứ tự giữa (LNR)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Hàm duyệt cây theo thứ tự sau (LRN)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Hàm tìm một nút có giá trị nhỏ nhất
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Hàm xóa một nút khỏi cây BST
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Nút có một hoặc không có con
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Nút có hai con: lấy nút nhỏ nhất ở cây con bên phải
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;

    // Chèn các phần tử vào cây BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Cay BST duyet theo thu tu truoc (NLR): ");
    preOrder(root);
    printf("\n");

    printf("Cay BST duyet theo thu tu giua (LNR): ");
    inOrder(root);
    printf("\n");

    printf("Cay BST duyet theo thu tu sau (LRN): ");
    postOrder(root);
    printf("\n");

    printf("Xoa 20\n");
    root = deleteNode(root, 20);
    printf("Cay BST sau khi xoa 20 (duyet theo thu tu giua): ");
    inOrder(root);
    printf("\n");

    printf("Xoa 30\n");
    root = deleteNode(root, 30);
    printf("Cay BST sau khi xoa 30 (duyet theo thu tu giua): ");
    inOrder(root);
    printf("\n");

    printf("Xoa 50\n");
    root = deleteNode(root, 50);
    printf("Cay BST sau khi xoa 50 (duyet theo thu tu giua): ");
    inOrder(root);
    printf("\n");

    return 0;
}
