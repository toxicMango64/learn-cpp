#pragma once

# include "AForm.hpp"

using std::cout;

class ShrubberyCreationForm: public AForm
{
	private:
		virtual void	executeConcrete() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
};
