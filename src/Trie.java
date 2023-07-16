/**
 * Trie
 *
 * @author: Wenhao Tong
 * @date: 2023/7/16
 */
public class Trie {

    public final Trie[] children;

    public Boolean isEnd;

    public Trie() {
        children = new Trie[26];
        isEnd = false;
    }

    public void insert(String word) {
        Trie node = this;
        for (int i = 0;i < word.length();i++) {
            char c = word.charAt(i);
            if (node.children[c - 'a'] == null) {
                node.children[c - 'a'] = new Trie();
            }
            node = node.children[c - 'a'];
        }
        node.isEnd = true;
    }

    public boolean search(String word) {
        Trie trie = getPrefix(word);
        return trie != null && trie.isEnd;
    }

    public boolean startsWith(String prefix) {
        Trie trie = getPrefix(prefix);
        return trie != null;
    }

    private Trie getPrefix(String prefix) {
        Trie node = this;
        for (int i = 0;i < prefix.length();i++) {
            char c = prefix.charAt(i);
            if (node.children[c - 'a'] == null) {
                return null;
            }
            node = node.children[c - 'a'];
        }
        return node;
    }
}