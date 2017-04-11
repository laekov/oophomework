#ifndef HEN_H
#define HEN_H
#include <vector>
class Hen {
	public:
		Hen();
		class Nest {
			public:
				Nest();
				class Egg {
					public:
						Egg();
						void display();
					private:
						int id;
				};
				void lay();
				void display();
			private:
				std::vector<Egg> eggs;
				int id;
		};
		void build();
		void lay(int, int);
		void display();
	private:
		std::vector<Nest> nests;
		int id;
};

#define MAX_ID	1000
#define BAD_ID	0x83838283
#endif

