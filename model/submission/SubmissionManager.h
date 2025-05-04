#ifndef SUBMISSIONMANAGER_H
#define SUBMISSIONMANAGER_H

#include <QList>
#include "Submission.h"

class SubmissionManager {
public:
    void addSubmission(const Submission& s);
    QList<Submission> getSubmissions() const;
    bool loadFromJson(const QString& filePath);

private:
    QList<Submission> m_submissions;
};

#endif // SUBMISSIONMANAGER_H
