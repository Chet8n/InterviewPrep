class Trie {
public:
	struct Node {
		Node* arr[26];
		bool isEnd;
		int cnt;

		Node() {
			for (int i = 0; i < 26; i++) {
				arr[i] = NULL;
			}
			isEnd = false;
			cnt = 1;
		}
	};

	char base = 'a';
	Node *root;
	Trie() {root = new Node(); }

	void insert (const string &s) {
		Node *cur = root;
		for (char ch : s) {
			if (!cur->arr[ch - base])
				cur->arr[ch - base] = new Node();
			else
				cur->arr[ch - base]->cnt += 1;
			cur = cur->arr[ch - base];
		}
		cur->isEnd = true;
	}

	bool search(const string& s) {
		Node *cur = root;
		for (char ch : s) {
			if (!cur->arr[ch - base])
				return false;
			cur = cur->arr[ch - base];
		}
		return (cur != NULL and cur->isEnd);
	}

};
