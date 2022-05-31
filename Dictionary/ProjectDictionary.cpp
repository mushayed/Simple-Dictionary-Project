#include<bits/stdc++.h>
using namespace std;
int ct = 0;

class node {
    public:
    string word;
    string meaning;
    node* left;
    node* right;

    node(string w, string m) {
        word = w;
        meaning = m;
        left = NULL;
        right = NULL;
    }
};

node* insertWord(node* root, string w, string m) {
    if(root == NULL) {
        return new node(w, m);
    }
    else if(w < root->word) {
        root->left = insertWord(root->left, w, m);
    }
    else if(w > root->word) {
        root->right = insertWord(root->right, w, m);
    }
    return root;
}

node* searchWord(node* root, string w) {
    if(root == NULL) {
        return root;
    }
    else if(w == root->word) {
        return root;
    }
    else if(w < root->word) {
        return searchWord(root->left, w);
    }
    else {
        return searchWord(root->right, w);
    }
}

void searchNearest(node* root, string w) {
    if(root == NULL) {
        return;
    }
    else if(w == root->word.substr(0, w.size())) {
        cout << "'" << root->word << "' ";
        ct++;
        searchNearest(root->left, w);
        searchNearest(root->right, w);
    }
    else if(w < root->word.substr(0, w.size())) {
        searchNearest(root->left, w);
    }
    else {
        searchNearest(root->right, w);
    }
}

node* inorderSuccessor(node* root) {
    node* curr = root;
    while(curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

node* deleteWord(node* root, string w) {
    if(root == NULL) {
        return root;
    }
    else if(w < root->word) {
        root->left = deleteWord(root->left, w);
    }
    else if(w > root->word) {
        root->right = deleteWord(root->right, w);
    }
    else {
        if(root->left == NULL) {
            node* temp = root->right;
            delete root;
            cout << "deleted successfully!" << endl;
            return temp;
        }
        else if(root->right == NULL) {
            node* temp = root->left;
            delete root;
            cout << "deleted successfully!" << endl;
            return temp;
        }
        node* temp = inorderSuccessor(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = deleteWord(root->right, temp->word);
    }
    return root;
}

void synonym(node* root, node* key) {
    if(root == NULL) {
        return;
    }
    if(root->meaning == key->meaning && root->word != key->word) {
        cout << "'" << root->word << "' ";
        ct++;
    }
    synonym(root->left, key);
    synonym(root->right, key);
}

void printInorder(node* root) {
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->word << " = " << root->meaning << endl;
    printInorder(root->right);
}

string removeSpace(string st) {
    string str = "";
    for(int i = 0; i < st.size(); i++) {
        if(st[i] != ' ') {
            str += st[i];
        }
        else if(i == st.size()-1) {
            return str;
        }
        else if(st[i+1] != ' ' && str != "") {
            str += st[i];
        }
    }
    return str;
}

string isValid(string st) {
    if(st.size() == 1) {
        return st;
    }
    string str = "";
    for(int i = 0; i < st.size(); i++) {
        if(st[i] != ' ') {
            str += st[i];
        }
        else if(i == st.size()-1) {
            return str;
        }
        else if(st[i+1] != ' ' && str != "") {
            str = "";
            break;
        }
    }
    return str;
}

int main() {
    // Default Storage
    node* root = NULL;
    root = insertWord(root, "Catch", "To grab something");
    insertWord(root, "Hold", "To grab something");
    insertWord(root, "Book", "A written or printed work consisting of pages glued or sewn together");
    insertWord(root, "Inventory", "A complete list of items");
    insertWord(root, "Record", "A complete list of items");
    insertWord(root, "Directory", "A complete list of items");
    insertWord(root, "House", "A building for human habitation");
    insertWord(root, "Home", "A building for human habitation");
    insertWord(root, "Residence", "A building for human habitation");
    insertWord(root, "Food", "Any nutritious substance that people or animals eat");
    insertWord(root, "Meal", "Any nutritious substance that people or animals eat");
    insertWord(root, "Teacher", "A person who teaches");
    insertWord(root, "Educator", "A person who teaches");
    insertWord(root, "Tutor", "A person who teaches");
    insertWord(root, "Instructor", "A person who teaches");
    insertWord(root, "Lecturer", "A person who teaches");
    insertWord(root, "Student", "A school pupil");
    insertWord(root, "Tutee", "A school pupil");
    insertWord(root, "Sample", "A small part or quantity intended to show what the whole is like");
    insertWord(root, "Example", "A small part or quantity intended to show what the whole is like");
    insertWord(root, "Case", "A small part or quantity intended to show what the whole is like");
    insertWord(root, "Schedule", "A plan for carrying out a process or procedure");
    insertWord(root, "Timetable", "A plan for carrying out a process or procedure");
    insertWord(root, "Scheme", "A plan for carrying out a process or procedure");
    insertWord(root, "Table", "A piece of furniture providing a level surface for eating, writing or working at");
    insertWord(root, "Bench", "A piece of furniture providing a level surface for eating, writing or working at");
    insertWord(root, "Desk", "A piece of furniture providing a level surface for eating, writing or working at");
    insertWord(root, "Country", "A nation with its own government,");
    insertWord(root, "State", "A nation with its own government");
    insertWord(root, "Kingdom", "A nation with its own government");
    insertWord(root, "Territory", "A nation with its own government");
    insertWord(root, "Apple", "One kind of fruit of round shape");
    insertWord(root, "Gadget", "A small mechanical or electronic device or tool");
    insertWord(root, "Joy", "A feeling of great pleasure and happiness");
    insertWord(root, "New", "Produced, introduced, or discovered recently for the first time");
    insertWord(root, "Old", "No longer young");
    insertWord(root, "Parents", "A person's father or mother");
    insertWord(root, "Quick", "Moving fast or doing something in a short time");
    insertWord(root, "University", "A high-level educational institution");
    insertWord(root, "Very", "In a high degree");
    insertWord(root, "Weight", "A body's relative mass or the quantity of matter contained by it");
    insertWord(root, "Xerox", "A xerographic copying process.");
    insertWord(root, "Yello", "One kind of color");
    insertWord(root, "Zoo", "An establishment which maintains a collection of wild animals");
    
    while(1) {
        cout << "\n----------- Dictionary -----------" << endl;
        cout << "1. Insert new word" << endl;
        cout << "2. Search meaning of a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Find Synonym" << endl;
        cout << "5. Print Dictionary" << endl;
        cout << "6. Exit" << endl;
        cout << "Please enter: ";

        string firstIn;
        cin >> firstIn;
 
        if(firstIn >= "1" && firstIn <= "5") {
            node* ele;
            string w, m;
            string res;
            int first = stoi(firstIn);
            switch (first)
            {
            case 1:
                cout << "Enter the word: ";
                getline(cin >> ws, w);

                res = isValid(w);
                if(res == "") {
                    cout << "Please input a valid word!" << endl;
                }
                else {
                    cout << "Enter the meaning of the word: ";
                    getline(cin >> ws, m);
                    w = removeSpace(w);
                    m = removeSpace(m);

                    transform(w.begin(), w.end(), w.begin(), ::tolower);
                    transform(m.begin(), m.end(), m.begin(), ::tolower);
                    w[0] = toupper(w[0]);
                    m[0] = toupper(m[0]);

                    insertWord(root, w, m);
                    cout << "'" << w << "' is successfully inserted!" << endl;
                }
                break;

            case 2:
                cout << "Enter the word: ";
                getline(cin >> ws, w);

                res = isValid(w);
                if(res == "") {
                    cout << "Please input a valid word!" << endl;
                } 
                else {
                    w = removeSpace(w);

                    transform(w.begin(), w.end(), w.begin(), ::tolower);
                    w[0] = toupper(w[0]);

                    ele = searchWord(root, w);

                    if(ele != NULL) {
                        cout << "'" << ele->word << "'" << " = " << ele->meaning << endl;
                    }
                    else {
                        ct = 0;
                        cout << "The word '" << w << "' was not found!" << endl;
                        cout << "Did you mean: ";
                        while(ct == 0 && w.size() > 0) {
                            searchNearest(root, w);
                            w.erase(w.size()-1);
                        }
                        if(ct == 0) {
                            cout << root->word;
                        }
                        cout << endl;
                    }
                }  
                break;

            case 3:
                cout << "Enter the word: ";
                getline(cin >> ws, w);

                res = isValid(w);
                if(res == "") {
                    cout << "Please input a valid word!" << endl;
                }
                else {
                    w = removeSpace(w);

                    transform(w.begin(), w.end(), w.begin(), ::tolower);
                    w[0] = toupper(w[0]);

                    ele = searchWord(root, w);

                    if(ele != NULL) {
                        cout << "'" << w << "' is ";
                        deleteWord(root, w);
                    }
                    else {
                        ct = 0;
                        cout << "The word '" << w << "' was not found!" << endl;
                        cout << "Did you mean: ";
                        while(ct == 0 && w.size() > 0) {
                            searchNearest(root, w);
                            w.erase(w.size()-1);
                        }
                        if(ct == 0) {
                            cout << root->word;
                        }
                        cout << endl;
                    }
                }
                break;

            case 4:
                cout << "Enter the word: ";
                getline(cin >> ws, w);

                res = isValid(w);
                if(res == "") {
                    cout << "Please input a valid word!" << endl;
                }
                else {
                    w = removeSpace(w);

                    transform(w.begin(), w.end(), w.begin(), ::tolower);
                    w[0] = toupper(w[0]);

                    ele = searchWord(root, w);

                    if(ele == NULL) {
                        ct = 0;
                        cout << "The word '" << w << "' was not found!" << endl;
                        cout << "Did you mean: ";
                        while(ct == 0 && w.size() > 0) {
                            searchNearest(root, w);
                            w.erase(w.size()-1);
                        }
                        if(ct == 0) {
                            cout << root->word;
                        }
                        cout << endl;
                    }
                    else {
                        ct = 0;
                        cout << "The synonyms for the word '" << w << "' are ";
                        synonym(root, ele);
                    
                        if(ct == 0) {
                            cout << "not found!";
                        }
                        cout << endl;
                    }
                }     
                break;

            case 5:
                cout << "\n-------All words with meaning-------" << endl;
                printInorder(root);  
                break;   
            }
        }
        else if(firstIn == "6") {
            cout << "The program is dismissed." << endl;
            break; 
        }
        else {
            cout << "Please press the correct button!" << endl;
        }
    }
    return 0;
}