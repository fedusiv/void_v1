
/*
	Please dont be greedy for comments.
	If you can leave comments, leave it
	
	Use this keywords to spesify comment's purpose:
	
		//TODO: - as placeholder with description of what should be here 
			or as reminder to yourself to add something
			
		//QUESTION: - if you don't understand or doupt other's code
		
		//SUGGESTION: - if you have an idea how to improve something
		
		//BUG: - if you see a possible error or undefined behavior
 */


// Class Name's always with Uppercase
class Example
{
	// brackets start from next line
	// not this 
	// if ( a > b){
	// }

	public:
		Example()
		{
			//Local var in method : 
			 int example_ = 1;

		}
	//Methods, which returns some variables have to be start from "get" 
	int getExample() 
	{
		return _Example;
	}
	//Methods, which set any value to  variable have to be start from "set" 
	void setExample(int example) 
	{
		_Example = example;
	}

	/* In cpp good to write description of methods in this style
	* @desc : description of method
	* @param : write somethg about argument1
	* @param : write somethg about argument2
	* @return : write somethg about return rapameter
	 */
	int exampleBigMethod(int argument1 , int argumetn2)
	{
		return argument1 + argumetn2;
	}

	public slots:
		// each slot have to started with word "on"
		void onExampleSlot();

	private:
		// local variables at Class
		int _Example;
		// asterix for pointers variables goes with Type
		int* _ExamplePointer;

}


/*
	Creating Files.
	Separate parts/features such as Items, Skills, must be in separate Folder.
	So if you in branch like features/stats, that means, for this must be separate folder, even there is just .cpp and .h files

	Creating branches, using name template 
	feature/add_something_new   feature/items_belt
	fix/fix_some_stuff			fix/item_belt_change_counting_algorithm
 */