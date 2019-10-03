struct dir_list
{
	char dir_name[20];
	char list[500];
};

program COMPUTE
{
	version COPMPUTE_VERS
	{
		string print_dir(dir_list)=1;
	}=2;
}=42356;


