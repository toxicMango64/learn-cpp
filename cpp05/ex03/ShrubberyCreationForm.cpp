
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{
	cout << "Default ShrubberyCreationForm got created" << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", target, 145, 137)
{
	cout << "ShrubberyCreationForm got created with the target: " << this->target << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm got destroyed" << "\n";
}


void	ShrubberyCreationForm::executeConcrete() const
{
	std::fstream	file_output;

	file_output.open(target + "_shrubbery", std::fstream::out | std::fstream::trunc);

	if (!file_output)
		std::cerr << "Error while opening Shrubbery target file" << "\n";

	file_output <<

"                                                   @@@@@\n"
"                                            @@@@@@@@@@@@@@@@@@@\n"
"                                       @@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"                                    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"                                  @@@@@@@@@@@               @@@@@@@@@@@\n"
"                  @@@@@@@@@@@@@@@@@@@@@@@@                     @@@@@@@@@\n"
"              @@@@@@@@@@@@@@@@@@@@@@@@@                           @@@@@@@@\n"
"           @@@@@@@@@@@@@@@@@@@@@@@@@@                               @@@@@@@\n"
"         @@@@@@@@@@@              @@                                 @@@@@@@\n"
"        @@@@@@@@@                                                     @@@@@@\n"
"      @@@@@@@@                                      @@                @@@@@@@\n"
"     @@@@@@@                                      @@@                  @@@@@@\n"
"     @@@@@@                                       @@                   @@@@@@@@@@\n"
"    @@@@@@                                      @@@                    @@@@@@@@@@@@@@@\n"
"   @@@@@@                                      @@@                     @@@@@@@@@@@@@@@@@@\n"
"   @@@@@@                                     @@@                             @@@@@@@@@@@@@\n"
"   @@@@@@                @                   @@@@                                  @@@@@@@@@@\n"
"   @@@@@@                @@                  @@@                                      @@@@@@@@\n"
"   @@@@@@                 @@                @@@@                                        @@@@@@@\n"
"    @@@@@                 @@@              @@@@                                          @@@@@@\n"
"    @@@@@@                 @@@            @@@@@                                           @@@@@@\n"
"     @@@@@@                  @@@          @@@@@                                           @@@@@@\n"
"     @@@@@@@@                 @@@@       @@@@@                              @@            @@@@@@@\n"
"      @@@@@@@@                 @@@@@     @@@@@                             @@             @@@@@@@\n"
"     @@@@@@@                     @@@@@@  @@@@@                           @@               @@@@@@\n"
"    @@@@@@@                        @@@@@@@@@@@                        @@@                 @@@@@@\n"
"   @@@@@@                            @@@@@@@@@                     @@@@                  @@@@@@\n"
"  @@@@@@@                               @@@@@@                 @@@@@@                  @@@@@@@\n"
"  @@@@@@                                @@@@@@          @@@@@@@@@@                   @@@@@@@@\n"
"  @@@@@@                                @@@@@@@@@@@@@@@@@@@@@                      @@@@@@@@@\n"
" @@@@@@@            @                   @@@@@@@@@@@@@@                      @@@@@@@@@@@@@@\n"
" @@@@@@@             @@                 @@@@@@@                             @@@@@@@@@@@@\n"
"  @@@@@@              @@@               @@@@@@@@                            @@@@@@@@@\n"
"  @@@@@@                @@@@            @@@@@@@@                           @@@@@@@\n"
"   @@@@@@                  @@@@@        @@@@@@@@                           @@@@@@\n"
"   @@@@@@@                    @@@@@@@@@@@@@@@@@@@                          @@@@@@\n"
"    @@@@@@@                       @@@@@@@@@@@@@@@                        @@@@@@@\n"
"     @@@@@@@@                           @@@@@@@@@@                      @@@@@@@\n"
"      @@@@@@@@@                        @@@@@@@@@@@@@                  @@@@@@@@\n"
"        @@@@@@@@@@                  @@@@@@@@@@@@@@@@@@@           @@@@@@@@@@@\n"
"          @@@@@@@@@@@@         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
"               @@@@@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@ @@@@@@@@@@@@@@@@\n"
"                    @@@@@@@@@@@@@          @@@@@@@@@@\n"
"                                           @@@@@@@@@@\n"
"                                           @@@@@@@@@@@\n"
"                                           @@@@@@@@@@@\n"
"                                            @@@@@@@@@@\n"
"                                            @@@@@@@@@@@\n"
"                                            @@@@@@@@@@@\n"
"                                            @@@@@@@@@@@\n"
"                                            @@@@@@@@@@@@\n"
"                                             @@@@@@@@@@@\n";

	file_output.close();
}
