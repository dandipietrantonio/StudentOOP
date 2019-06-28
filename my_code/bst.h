#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst {
        friend void print_bst(const Bst<T>& bst, int level=0) {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

    public:
        Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
            : data(d), parent(p), left(l), right(r) {}

        Bst<T>* insert(const T d) {
           if (data == d) return nullptr;
            else if (data > d) {
                if (left) return left->insert(d);
                else {
                    left = new Bst(d, this);
                    return left;
                }
            }
            else {
                if (right) return right->insert(d);
                else {
                    right = new Bst(d, this);
                    return right;
                }
            }
        } 

        T get_val() const {
            return data;
        }
    
        T min() const {
            if (!left) return data;
            else return left->min();
        }

        T max() const {
            if (!right) return data;
            else return right->max();
        }

        Bst<T>* search(T val) {
            if (data == val) return this;
            else if (data < val) {
                if (right) return right->search(val);
                else return nullptr;
            }
            else {
                if (left) return left->search(val);
                else return nullptr;
            }
        }

        Bst<T>* predecessor(T val) {
            Bst<T>* cur = search(val);
            if (cur->left) {
                cur = cur->left;
                while (cur->right) {
                    cur = cur->right;
                }
                return cur;
            }
            else if (cur->parent) {
                while ((cur->parent)->data > cur->data) {
                    cur = cur->parent;
                }
                return cur->parent;
            }
            else return nullptr;
        }

        Bst<T>* successor(T val) {
            Bst<T>* cur = search(val);
            if (cur->right) {
                cur = cur->right;
                while (cur->parent->data < cur->data) {
                    cur = cur->parent;
                }
                return cur;
            }
            else if (cur->parent) {
                while ((cur->parent)->data < cur->data) {
                    cur = cur->parent;
                }
                return cur->parent;
            }
            else return nullptr;
        }

    private:
        T data;
        Bst* parent;
        Bst* left;
        Bst* right;
};