from pprint import pprint


class Solution:
    def numUniqueEmails(self, emails: 'List[str]') -> 'int':
        unique_email_set = set()
        for email in emails:
            # spliting the email into local name and domain name
            local, domain = email.split('@')
            # if '+' is found, remove the characters from '+' onward from local name
            if '+' in local:
                local = local[:local.index('+')]
            # if '.' is found, remove it from the local name
            if '.' in local:
                local = local.replace('.', '')
            # put canonical form email into the unique email list
            unique_email_set.add(local+'@'+domain)
        return len(unique_email_set)

    def emailPrint(self, emails: 'List[str]') -> 'None':
        pprint(emails)


if __name__ == '__main__':
    unique_email = Solution()
    emails = ["test.email+alex@leetcode.com",
              "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com", "test.email+dav.id@lee.tcode.com"]
    unique_email.emailPrint(emails)
    print(unique_email.numUniqueEmails(emails))
