#pragma once

#include <string>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int	grade;

	public:
		void	signForm(AForm &AForm);
		void	executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int newGrade);
		void				incrementGrade(void);
		void				decrementGrade(void);

		Bureaucrat();
		Bureaucrat(const Bureaucrat& in);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& in);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& in);