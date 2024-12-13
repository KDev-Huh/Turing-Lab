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
		Book(L"ȫ�浿��", L"���", L"������", Category::NOVEL, 3400),
		Book(L"����ġ��", L"�̻�", L"����", Category::NOVEL, 2400),
		Book(L"�ѱռ�", L"���� ���̾Ƹ��", L"����", Category::HUMANITIES, 28000),
		Book(L"��ȭ�� ��������", L"���", L"������", Category::HUMANITIES, 23400),
		Book(L"�ҳ��߾�", L"������", L"�߾��Ϻ�", Category::MAGAZINE, 7400),
		Book(L"�����", L"������", L"��ȭ��", Category::MAGAZINE, 2800),
		Book(L"���ַ�", L"���ݷ� ��Ű�ƺ���", L"����", Category::HUMANITIES, 3400),
		Book(L"12 ����Ʃ��", L"������", L"�����ڸ���", Category::MAGAZINE, 8600),
		Book(L"11 ����Ʃ��", L"������", L"�����ڸ���", Category::MAGAZINE, 8600),
		Book(L"10 ����Ʃ��", L"������", L"�����ڸ���", Category::MAGAZINE, 8600),
	};
	
	std::cout << main << std::endl;

	std::sort(books.begin(), books.end(), fp[PRICE]);

	for (auto bk : books)
		std::wcout << bk.info() << std::endl;


	return 0;
}