#ifndef FT_BUFF_H
# define FT_BUFF_H

# include <string>

# define BUFF_SIZE 4096

typedef struct		s_buff
{
	char			buff[BUFF_SIZE];
	size_t			index;
	struct s_buff	*next;
}					t_buff;

class ft_Buff
{
	ft_Buff(void);
	~ft_Buff(void);

	public:
	void			append(char *str, size_t len);
	void			append(char c);
	std::string		to_string(void);

	private:
	void			alloc_link(void);
	t_buff			m_buff;
	t_buff			*m_current_link;
};

#endif
