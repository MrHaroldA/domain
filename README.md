Multi Domain module for Backdrop CMS.

This is a solution to run multiple sites on a single Backdrop installation. All (node) content and users are shared between different domains with an option to limit both content and user accounts to a single, multiple, or all domains.

Domains themself are fieldable entities, so you can easily add your own metadata, which can be easily displayed using Views.

THIS MODULE IS FAR FROM FINISHED! In fact, it's more like a semi-working proof of concept ;)

Requirements
------------
- An up-to-date Backdrop CMS installation

Features
------------
- Limit node content to selected domains using node_access_records()
- Manage Domain entities
- Assign domains to user accounts

Todo
------------
- Limit user logins to assigned domains
- Add support for more entity types, like Taxonomy.
- General clean-ups, speed-ups, and a lot of fixes ;)
