#ifndef PROCESSES_MANAGER_H
#define PROCESSES_MANAGER_H

#include <dirent.h>
#include <log4cxx/logger.h>
#include "process.h"
#include "freedesktop/desktop_files.h"
#include "freedesktop/desktop_file.h"

class ProcessesManager
{
  public:
    /*
    ** Constructors and Destructor
    */
    ProcessesManager();
    virtual ~ProcessesManager();

    /*
    ** Instance methods
    */
    void                            set_desktop_files(const DesktopFiles * desktop_files);
    const Process *                 find_or_create_from_path(const std::string & path);

  private:
    log4cxx::LoggerPtr              logger;
    const DesktopFiles *            desktop_files;
    std::map<std::string, Process>  processes;

    Process *                       make_new_process(Process * new_process);
};

#endif
