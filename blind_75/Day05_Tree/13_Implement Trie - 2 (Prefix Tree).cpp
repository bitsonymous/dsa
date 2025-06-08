struct Node{
    Node* links[26];
    int ew = 0;
    int ep = 0;
    bool containsKey(char c){
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node* node){
        links[c -'a'] = node;
    }
    Node* get(char c){
        return links[c - 'a'];
    }
    void increasePrefix(){
        ep++;
    }
    void increaseEnd(){
        ew++;
    }
    int getPrefCount(){
        return ep;
    }
    int wordCount(){
        return ew;
    }
    void reducePref(){
        ep--;
    }
    void deleteEnd(){
        ew--;
    }
};


class Trie {
    private:
        Node* root;
	public:
	    Trie() {
	        root = new Node();
	    }

	    void insert(string word) {
	        Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
                node->increasePrefix();
            }
            node->increaseEnd();
    	}

	    int countWordsEqualTo(string word) {
	        Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                }else{
                    return 0;
                }
            }
            return node->wordCount();
    	}

	    int countWordsStartingWith(string word) {
	        Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                }else{
                    return 0;
                }
                
            }
            return node->getPrefCount();
    	}

	    void erase(string word) {
            Node* node = root;
            for(int i = 0; i<word.size(); i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    node->reducePref();
                }else{
                    return ;
                }
            }
            node->deleteEnd();
	    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */