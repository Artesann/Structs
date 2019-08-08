
struct Bus	
{
	int busRoute;
	char name[64];
};
class map {

private:
	class node {
	public:
		node * parent;
		node *left;
		node *right;
		Bus  data;
		int key;

		node(Bus data, int key, node*parent = NULL, node*left = NULL, node*right = NULL) {
			this->data = data;
			this->left = left;
			this->parent = parent;
			this->right = right;
			this->key = key;

		}
	};

public:
	map();
	~map();


	/////////////////
	node *root;
	void push(Bus data, int key);
	void push(node*p, Bus data, int key);
	void show(node*p);
	node* right(node* p) { if (p->right == nullptr) return p; else right(p->right); }
	node* left(node* p) { if (p->left == nullptr) return p; else left(p->left); }
	void save();
	void save(node* p);
	void showAll();
	void removeAt(int key);
	node* searchAr(int key) { return searchAr(root, key); }
	node* searchAr(node* p, int key) {
		if (p) {
			if (p->key == key) {
				return p;
			}
			else if (p->key <= key) {
				return searchAr(p->right, key);
			}
			else {
				return searchAr(p->left, key);
			}
		}
		else {
			cout << "Ñëîâî íå íàéäåíî â ñëîâàðå.";
		}
	}

};

map::map() {
	root = nullptr;

}

map::~map() {
	//clear();
}

void map::push(Bus data, int key)
{
	if (root == nullptr) {
		node* new_root = new node(data, key);
		this->root = new_root;
	}
	else {
		push(root, data, key);
	}
}

void map::push(node* p, Bus data, int key) {
	if (p) {
		if (p->key <= key) {
			if (p->right == nullptr) {
				p->right = new node(data, key, p);
			}
			else {
				push(p->right, data, key);
			}
		}
		else {
			if (p->left == nullptr) {
				p->left = new node(data, key, p);
			}
			else {
				push(p->left, data, key);
			}
		}
	}

}


void map::show(node* p)
{
	if (p != nullptr)
	{
		show(p->left);
		cout << p->key << "  ";
		cout << p->data.busRoute << "  ";
		cout << p->data.name << "  ";
		cout << endl;
		show(p->right);
	}
}

void map::save()
{
	if (root) {

		Bus b;
		int key;
		ofstream fout("file1.txt", ios_base::app);
		if (root->left)	save(root->left);
		b = root->data;
		key = root->key;
		fout.write((char*)&key, sizeof(key));
		fout.write((char*)&b, sizeof(Bus));
		if (root->right) save(root->right);
	}
}
void map::save(node* p)
{
	if (p) {
		Bus b;
		int key;
		ofstream fout("file1.txt", ios_base::app);
		if (p->left) save(p->left);
		b = p->data;
		key = p->key;
		fout.write((char*)&key, sizeof(key));
		fout.write((char*)&b, sizeof(Bus));
		if (p->right) save(p->right);
	}
}
void map::showAll()
{
	if (root != nullptr)
	{
		show(root->left);
		cout << root->key << " ";
		//root->data.printBus();
		cout << endl;
		show(root->right);
	}
}


void map::removeAt(int key)
{
	if (root->key == key) {
		node* toLeft = root->left;
		if (root->right) {
			root = root->right;
		}
		if (root->left) {
			left(root)->left = toLeft;
		}
	}
	else {
		node* toDelete = searchAr(key);
		if (toDelete->parent->right == toDelete) {
			if (toDelete->right) {
				toDelete->parent->right = toDelete->right;
				if (toDelete->left) {
					left(toDelete->right)->left = toDelete->left;
				}
			}

			else if (!toDelete->right && toDelete->left) {
				toDelete->parent->right = toDelete->left;
			}
			else if (!toDelete->left && !toDelete->right) {
				toDelete->parent->right = nullptr;
			}
		}
		if (toDelete->parent->left == toDelete) {
			if (toDelete->right) {
				toDelete->parent->left = toDelete->right;
				if (toDelete->left) {
					left(toDelete->right)->left = toDelete->left;
				}
			}

			else if (!toDelete->right && toDelete->left) {
				toDelete->parent->left = toDelete->left;
			}
			else if (!toDelete->left && !toDelete->right) {
				toDelete->parent->left = nullptr;
			}
		}
		delete toDelete;
	}
}






int main()
{
	setlocale(LC_ALL, "ru");
	map in;
	map out;
	Bus boof;
	int key;
	bool Work = true;
	int fordo;
	string busin = "BusIn.txt";
	string busout = "BusOut.txt";

	ifstream fin_in;
	fin_in.open(busin, ios_base::app);
	while (fin_in.read((char*)&key, sizeof(key))) {
		fin_in.read((char*)&boof, sizeof(Bus));
		in.push(boof, key);
	}

	fin_in.close();

	ifstream fin_out;
	fin_out.open(busout, ios_base::app);
	while (fin_out.read((char*)&key, sizeof(key))) {
		fin_out.read((char*)&boof, sizeof(Bus));
		out.push(boof, key);
	}

	fin_out.close();


	cout << "1  Âûâåñòè ñïèñêè àâòîáóñîâ" << endl;
	cout << "2  Âûåçä àâòîáóñà" << endl;
	cout << "3  Âúåçä àâòîáóñà" << endl;
	cout << "4  Äîáàâëåíèå àâòîáóñà" << endl;


	while (Work) {

		cin >> fordo;
		switch (fordo) {
		case 1: {
			cout << "Ñïèñîê àâòîáóñîâ â ïàðêå"<<endl;
			in.showAll();
			cout << "Ñïèñîê àâòîáóñîâ âíå ïàðêà"<<endl;
			out.showAll();
			break;
		}
		case 2: {
			cout << "Âûåçä àâòîáóñà èç ïàðêà" << endl;
			cout << "Ââåäèòå íîìåð àâòîáóñà" << endl;
			int s;
			cin >> s;
			out.push(in.searchAr(s)->data, s);
			in.removeAt(s);
			break;
		}
		case 3: {
			cout << "Âúåçä àâòîáóñà â ïàðêà" << endl;
			cout << "Ââåäèòå íîìåð àâòîáóñà" << endl;
			int s;
			cin >> s;
			in.push(out.searchAr(s)->data, s);
			out.removeAt(s);
			break;
		}
		case 4: {
			cout << "Äîáàâëåíèå àâòîáóñà(â ïàðê)" << endl;
			cout << "Íîìåð àâòîáóñà:     "; 
			cin >> key;
			cout << "Íîìåð ìàðøðóòà:     ";
			cin >> boof.busRoute;
			cout << "Èìÿ âîäèòåëÿ:       ";
			cin >> boof.name;
			in.push(boof, key);

			break;
		}
		{
		default:
			break;
		}
		}
	}

	out.save();
	in.save();
	
	return 0;
}

