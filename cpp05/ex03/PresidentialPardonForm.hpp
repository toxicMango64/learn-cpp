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
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
};
