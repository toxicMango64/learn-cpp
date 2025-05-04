#pragma once

# include "AForm.hpp"

using std::cout;

class RobotomyRequestForm: public AForm
{
	private:
		virtual void	executeConcrete() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
};
