
#include "GetLocalFileListAt.h"
#include "CharacterSet.h"
#ifndef _WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#endif
void TVPGetLocalFileListAt(const ttstr &name, const std::function<void(const ttstr&, tTVPLocalFileInfo*)>& cb) {
	DIR *dirp;
	struct dirent *direntp;
	tTVP_stat stat_buf;
	tjs_string wname(name.AsStdString());
	std::string nname;
	if( TVPUtf16ToUtf8(nname, wname) ) {
		if ((dirp = opendir(nname.c_str())))
		{
			while ((direntp = readdir(dirp)) != NULL)
			{
				struct stat file_info;
				stat(direntp->d_name, &file_info);
#if 0
				if( direntp->d_type == DT_REG )
#endif
				if (S_ISREG(file_info.st_mode))
				{
					std::string fullpath = nname + "/" + direntp->d_name;
					if (!TVP_stat(fullpath.c_str(), stat_buf))
						continue;
					ttstr file(direntp->d_name);
					if (file.length() <= 2) {
						if (file == TJS_W(".") || file == TJS_W(".."))
							continue;
					}
					tjs_char *p = file.Independ();
					while (*p)
					{
						// make all characters small
						if (*p >= TJS_W('A') && *p <= TJS_W('Z'))
							*p += TJS_W('a') - TJS_W('A');
						p++;
					}
					tTVPLocalFileInfo info;
					info.NativeName = direntp->d_name;
					info.Mode = stat_buf.st_mode;
					info.Size = stat_buf.st_size;
					info.AccessTime = stat_buf.st_atime;
					info.ModifyTime = stat_buf.st_mtime;
					info.CreationTime = stat_buf.st_ctime;
					cb(file, &info);
				}
			}
			closedir(dirp);
		}
	}
}