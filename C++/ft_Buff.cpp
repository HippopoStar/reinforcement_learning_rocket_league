#include "ft_Buff.h"

/**
 * Constructor & Destructor
 */

ft_Buff::ft_Buff(void)
{
	m_buff.index = 0;
	m_buff.next = NULL;
	m_current_link = &m_buff;
}

ft_Buff::~ft_Buff(void)
{
	t_buff		*tmp;

	while (!((tmp = m_buff.next) == NULL))
	{
		m_buff.next = (m_buff.next)->next;
		delete tmp;
	}
}

/**
 * Private function(s)
 */

void		ft_Buff::alloc_link(void)
{
	m_current_link->next = new t_buff;
	m_current_link->next->index = 0;
	m_current_link->next->next = NULL;
	m_current_link = m_current_link->next;
}

/**
 * Public function(s)
 */

void		ft_Buff::append(char *str, size_t len)
{
	size_t		i;

	i = BUFF_SIZE - m_current_link->index;
	if (len > i)
	{
		(*this).append(str, i);
		(*this).alloc_link();
		(*this).append(str + i, len - i);
	}
	else
	{
		i = 0;
		while (!(*(str + i) == '\0') && i < len)
		{
			*(m_current_link->buff + m_current_link->index + i) = *(str + i);
			i++;
		}
		m_current_link->index = m_current_link->index + len;
	}
}

void		ft_Buff::append(char c)
{
	if (m_current_link->index == BUFF_SIZE)
	{
		(*this).alloc_link();
	}
	*(m_current_link->buff + m_current_link->index) = c;
	(m_current_link->index)++;
}

std::string	ft_Buff::to_string(void)
{
	t_buff		*tmp;
	std::string	my_string;

	tmp = &m_buff;
	while (!(tmp == NULL))
	{
		my_string.append(tmp->buff, tmp->index);
		tmp = tmp->next;
	}
	return (my_string);
}
