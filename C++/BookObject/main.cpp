import book;
import <iostream>;
import <locale>;
import <vector>;
import <algorithm>;

enum Key {
	TITLE, AUTH, PUB, PRICE
};

int main() {
	setlocale(LC_ALL, "");

	bool(*fp[4])(Book, Book) = {
		[](Book b1, Book b2) { return b1.title() < b2.title(); },
		[](Book b1, Book b2) { return b1.author() < b2.author(); },
		[](Book b1, Book b2) { return b1.publisher() < b2.publisher(); },
		[](Book b1, Book b2) { return b1.price() < b2.price(); },
	};
	
	std::vector<Book> books{
		Book(L"홍길동전", L"허균", L"낙동강", Category::NOVEL, 3400),
		Book(L"전우치전", L"미상", L"동강", Category::NOVEL, 2400),
		Book(L"총균쇠", L"재라드 다이아몬드", L"새벽", Category::HUMANITIES, 28000),
		Book(L"문화의 수수께끼", L"허균", L"낙동강", Category::HUMANITIES, 23400),
		Book(L"소년중앙", L"편집부", L"중앙일보", Category::MAGAZINE, 7400),
		Book(L"어께동무", L"편집부", L"문화사", Category::MAGAZINE, 2800),
		Book(L"군주론", L"니콜로 마키아벨리", L"새벽", Category::HUMANITIES, 3400),
		Book(L"12 월단튜턴", L"편집부", L"뉴턴코리아", Category::MAGAZINE, 8600),
		Book(L"11 월단튜턴", L"편집부", L"뉴턴코리아", Category::MAGAZINE, 8600),
		Book(L"10 월단튜턴", L"편집부", L"뉴턴코리아", Category::MAGAZINE, 8600),
	};
	
	std::cout << main << std::endl;

	std::sort(books.begin(), books.end(), fp[PRICE]);

	for (auto bk : books)
		std::wcout << bk.info() << std::endl;


	return 0;
}