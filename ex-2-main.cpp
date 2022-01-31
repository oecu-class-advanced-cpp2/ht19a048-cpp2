#include <iostream>
#include <string>

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi
		指定された文字列を解析して、オブジェクトを初期化します。
		以下の場合には例外が創出されます。
		1. [2-9,m,c,x,i] 以外の文字が出現した場合
		2. 2 文字続けて数字 (2-9) が出現した場合
		3. m, c, x, i がこの順序で出現しなかった場合
		ただし、例えば mx のように、特定の文字をスキップする事は許容
		されます。
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {
			int num = 1;
            
            
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
                
                

				if (int(*pos) >= 50 && 57 >= int(*pos)) {
					//2-9
					if (num > 1) {
						//2.例外処理 数字連続
						std::cout <<*pos<< ":mcxi記法では数字の連続はない" << std::endl;
					}
					else {
						num = int(*pos) - 48;
					}
				}
				else {
                    
					//mcxi
					switch (int(*pos)){
                            
                            
					//条件分岐＆3.例外処理 順序違反
					case 109:
						if (value_ == 0) {
							num *= 1000;
							value_ += num;
							num = 1;
						}
						else{
							std::cout <<":mcxi記法の英字はmcxiの順に記載する" << std::endl;
						}
						break;//m
                            
					case 99:
						if (value_ % 1000 == 0) {
							num *= 100;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi記法の英字はmcxiの順に記載する" << std::endl;
						}
						break;//c
					case 120:
						if (value_ % 100 == 0) {
							num *= 10;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi記法の英字はmcxiの順に記載する" << std::endl;
						}
						break;//x
                            
					case 105:
						if (value_ % 10 == 0) {
							num *= 1;
							value_ += num;
							num = 1;
						}
						else {
							std::cout << ":mcxi記法の英字はmcxiの順に記載する" << std::endl;
						}
						break;//i
					//1.例外処理 文字違反
					default:
						std::cout<<":mcxi記法に "<<*pos<<" は含まれない"<<std::endl;
					}
				}
			}
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+
		2 つのオブジェクトの加算結果を取得します。
		*/
		/* ----------------------------------------------------------------- */
		mcxi operator+(const mcxi& rhs) {
			mcxi a("");
			a.value_ = this->value_ + rhs.value_;
			return a;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string
		現在の値を mcxi 記法に変換します。
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::string b;
			if (value_ / 1000 >= 2) {
				b += (value_ / 1000)+48;
			}
			if (value_ / 1000 >= 1) {
				b += 'm';
			}
			if ((value_ % 1000) / 100 >= 2) {
				b += ((value_ % 1000) / 100) + 48;
			}
			if ((value_ % 1000) / 100 >= 1) {
				b += 'c';
			}
			if ((value_ % 100) / 10 >= 2) {
				b += ((value_ % 100) / 10) + 48;
			}
			if ((value_ % 100) / 10 >= 1) {
				b += 'x';
			}
			if ((value_ % 10) >= 2) {
				b += (value_ % 10) + 48;
			}
			if ((value_ % 10) >= 1) {
				b += 'i';
			}
			return b;
		}

		void debug_mcxi() {
			std::cout << "value_: " << value_ << std::endl;
		}


	private:
		int value_;
	};
}

int main() {
    
    

	cpp2::mcxi a0("1m2c4");
	a0.debug_mcxi();
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	cpp2::mcxi a1("mcc4i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
    
	cpp2::mcxi a2("“m2c0x4i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("2cm4i");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("99x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
    /*
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
    
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
    
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
    
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
    
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
    
*/
}