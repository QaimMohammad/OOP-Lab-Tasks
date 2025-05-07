#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct User {
    string id, first_name, last_name, address, email;
};

struct Product {
    string id, name, description;
    int price;
};

struct Order {
    string id, user_id, product_id;
    int total_paid;
};

int main() {
    vector<User> users = {
        {"U1", "Linus", "Torvalds", "Linux St", "linus@example.com"},
        {"U2", "Ada", "Lovelace", "Math Ave", "ada@algo.com"}
    };

    vector<Product> products = {
        {"P1", "Laptop", "High-end", 1200},
        {"P2", "Keyboard", "Mechanical", 150}
    };

    vector<Order> orders = {
        {"O1", "U1", "P1", 1200},
        {"O2", "U2", "P2", 150}
    };

    ofstream ufile("users.txt"), pfile("products.txt"), ofile("orders.txt");
    for (auto& u : users) ufile << u.id << "," << u.first_name << "," << u.last_name << "," << u.address << "," << u.email << "\n";
    for (auto& p : products) pfile << p.id << "," << p.name << "," << p.description << "," << p.price << "\n";
    for (auto& o : orders) ofile << o.id << "," << o.user_id << "," << o.product_id << "," << o.total_paid << "\n";
    ufile.close(); pfile.close(); ofile.close();

    ifstream uin("users.txt"), oin("orders.txt"), pin("products.txt");
    string line;
    string linus_id = "";
    while (getline(uin, line)) {
        stringstream ss(line);
        string id, fname;
        getline(ss, id, ',');
        getline(ss, fname, ',');
        if (fname == "Linus") {
            linus_id = id;
            break;
        }
    }

    vector<string> linus_product_ids;
    while (getline(oin, line)) {
        stringstream ss(line);
        string oid, uid, pid;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        getline(ss, pid, ',');
        if (uid == linus_id) linus_product_ids.push_back(pid);
    }

    map<string, string> product_name_map;
    while (getline(pin, line)) {
        stringstream ss(line);
        string pid, pname;
        getline(ss, pid, ',');
        getline(ss, pname, ',');
        product_name_map[pid] = pname;
    }

    cout << "Products ordered by Linus:\n";
    for (auto& pid : linus_product_ids) {
        cout << product_name_map[pid] << "\n";
    }

    return 0;
}

