/*
 * NotebookDocQueue.hpp
 *
 * Copyright (C) 2009-16 by RStudio, Inc.
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef SESSION_NOTEBOOK_DOC_QUEUE_HPP
#define SESSION_NOTEBOOK_DOC_QUEUE_HPP

#include "NotebookQueue.hpp"
#include "NotebookQueueUnit.hpp"

#include <core/json/Json.hpp>
#include <list>

namespace rstudio {

namespace core {
   class Error;
   class FilePath;
}

namespace session {
namespace modules {
namespace rmarkdown {
namespace notebook {

class NotebookDocQueue
{
public:
   NotebookDocQueue(const std::string& docId, const std::string& jobDesc, 
         int pixelWith, int charWidth);
   core::Error update(const boost::shared_ptr<NotebookQueueUnit> unit, 
      QueueOperation op, const std::string& before);
   core::json::Object toJson() const; 
   std::string docId() const;
   int pixelWidth() const;
   int charWidth() const;
   boost::shared_ptr<NotebookQueueUnit> firstUnit();

private:
   std::string docId_;
   std::string jobDesc_;
   int pixelWidth_;
   int charWidth_;

   // the queue of chunks to be executed 
   std::list<boost::shared_ptr<NotebookQueueUnit> > queue_;
};

} // namespace notebook
} // namespace rmarkdown
} // namespace modules
} // namespace session
} // namespace rstudio

#endif
