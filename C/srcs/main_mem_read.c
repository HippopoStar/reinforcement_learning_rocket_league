#define _GNU_SOURCE
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

void	print_args(unsigned char *addr, size_t size)
{
	printf("addr: %p\n", addr);
	printf("size: %lu\n", size);
}

void	raw_print(unsigned char *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("Avant le test\n");
		if (*(addr + i) == '\0')
		{
			printf("Apres le test\n");
			write(1, "\\0", 2);
		}
		else
		{
			write(1, "_", 1);
//			write(1, &(*(addr + i)), 1);
		}
		i++;
	}
}

int		dev_mem(unsigned char *addr, size_t size)
{
	int		fd;
	char	buffer[1024];
	int		ret_val;

	(void)size;
	if ((fd = open("/dev/mem", O_RDONLY)) == -1)
	{
		printf("Failed to open file\n");
	}

	else if (lseek(fd, (off_t)addr, SEEK_SET) == -1)
	{
		printf("Failed to move cursor within file\n");
	}

	else if ((ret_val = read(fd, buffer, 512)) == -1)
	{
		printf("Failed to read within file\n");
	}

	else
	{
		buffer[512] = '\0';
		printf("%s\n", buffer);
	}

	if (!(fd == -1))
	{
		close(fd);
	}

	return (0);
}

void	get_ids(void)
{
	uid_t	ruid;
	uid_t	euid;
	uid_t	suid;
	gid_t	rgid;
	gid_t	egid;
	gid_t	sgid;

	getresuid(&ruid, &euid, &suid);
	getresgid(&rgid, &egid, &sgid);
	printf("ruid: %d | euid: %d | suid: %d\n", ruid, euid, suid);
	printf("rgid: %d | egid: %d | sgid: %d\n", rgid, egid, sgid);
}

int		read_remote_process_memory(pid_t pid, void *address, size_t size)
{
	ssize_t			ret_val;
	struct iovec	local_iov;
	struct iovec	remote_iov;
	char			buff_local[132 * 8];

	(void)size;
	local_iov.iov_base = (void *)buff_local;
	local_iov.iov_len = (size_t)132 * 8;
	remote_iov.iov_base = (void *)address;
	remote_iov.iov_len = (size_t)132 * 8;
	printf("remote_iov.iov_base: %p\n", remote_iov.iov_base);
	perror(strerror(errno));
	ret_val = process_vm_readv(pid, &local_iov, 1, &remote_iov, 1, 0);
	if (ret_val == -1)
	{
		perror(strerror(errno));
	}
	else
	{
		printf("I've readen some characters !\n");
	}
	printf("process_vm_readv: %ld\n", ret_val);
	ret_val = write(1, buff_local, 132 * 8);
	write(1, "\n", 1);
	printf("write: %ld\n", ret_val);
	return (ret_val);
}	

int		main(int argc, char **argv)
{
	pid_t			pid;
	unsigned char	*addr;
	size_t			size;

	get_ids();
	if (argc > 2)
	{
		if (argc > 3)
		{
			pid = strtoul(*(argv + 3), NULL, 10);
			printf("pid: %u\n", pid);
			if (setpgid(0, pid) == -1)
			{
				printf("Unable to set GID\n");
			}
			errno = 0;
		}
		addr = (unsigned char *)strtoull(*(argv + 1), NULL, 16);
		size = (size_t)strtoull(*(argv + 2), NULL, 10);
		print_args(addr, size);
		read_remote_process_memory(pid, (void *)addr, size);
//		write(1, addr, size);
//		raw_print(addr, size);
//		dev_mem(addr, size);
	}
	else
	{
		printf("Le programme prend 2 parametres en argument\n");
		printf("(+ un eventuel 3eme parametre correspondant au PID)\n");
	}
	perror(strerror(errno));
	return (0);
}
