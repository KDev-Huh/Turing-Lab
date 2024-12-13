export module book;

import <string>;
import <vector>;

class Book;

export struct Category {
	static const unsigned int NOVEL = 0;
	static const unsigned int SF = 1;
	static const unsigned int SCIENCE = 2;
	static const unsigned int ART = 3;
	static const unsigned int HUMANITIES = 4;
	static const unsigned int MAGAZINE = 5;
	static const std::vector<std::wstring> CATEGORY;

	friend class Book;	// book은 이제 private에 마음데로 접근 가능
private:
	unsigned int value;
};

export class Book {
private:
	std::wstring _title; // wchar_t
	std::wstring _author;
	std::wstring _publisher;
	Category _category;
	double _price;
public:
	Book(const std::wstring& title, const std::wstring& author, const std::wstring& publisher,
		unsigned int category, double price);

	std::wstring title() const;
	std::wstring author() const;
	std::wstring publisher() const;
	Category category() const;
	double price() const;

	void title(const std::wstring&);
	void author(const std::wstring&);
	void publisher(const std::wstring&);
	void category(Category);
	void price(double);

	std::wstring info() const;
};