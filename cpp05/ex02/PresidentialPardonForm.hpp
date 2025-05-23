#pragma once

# include "AForm.hpp"

using std::cout;

class PresidentialPardonForm: public AForm
{
	private:
		virtual void	executeConcrete() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();
};
