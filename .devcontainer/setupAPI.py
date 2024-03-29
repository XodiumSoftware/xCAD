import logging

import requests


class SetupAPI:
    """A class to setup the API for the Bricsys-API repository."""

    def __init__(
        self, org_name: str, repo_name: str, access_token: str
    ) -> None:
        """Initialize the class.

        Args:
            org_name (str): The name of the organization.
            repo_name (str): The name of the repository.
            access_token (str): The access token.
        """
        self.session = requests.Session()
        self.session.headers.update(
            {
                'Authorization': f'token {access_token}',
                'Accept': 'application/vnd.github.v3+json',
            }
        )

        self.base_url = (
            f'https://api.github.com/repos/{org_name}/{repo_name}/contents'
        )

        logging.basicConfig(level=logging.INFO)
        self.logger = logging.getLogger(__name__)

    def get_contents(self, path: str = '') -> None:
        """Get the contents of the repository.

        Args:
            path (str, optional): The path to the repository. Defaults to ''.
        """
        url = f'{self.base_url}/{path}'
        try:
            response = self.session.get(url)
            response.raise_for_status()
        except requests.exceptions.RequestException as e:
            self.logger.error(f'Request failed: {e}')
            raise

        data = response.json()

        for file in data:
            if file['type'] == 'dir':
                self.get_contents(file['path'])
            else:
                self.logger.info(file['download_url'])

        if 'next' in response.links:
            self.get_contents(response.links['next']['url'])


SetupAPI(
    'Structura-Engineering',
    'Bricsys-API',
    '',
).get_contents()
