#ifndef SUBMISSIONMANAGER_H
#define SUBMISSIONMANAGER_H

#include <QList>
#include "Submission.h"
#include "JsonUtils.h"

class SubmissionManager : public JsonUtils<Submission>
{
public:
    SubmissionManager() = default;
    ~SubmissionManager() = default;

};

#endif // SUBMISSIONMANAGER_H
