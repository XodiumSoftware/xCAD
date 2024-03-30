import logging
import os
import tempfile
import zipfile
from getpass import getpass
from urllib.parse import urlparse

import requests


class SetupAPI:
    """A class to setup the API for the Bricsys-API repository."""

    def __init__(
        self,
        org_name: str,
        repo_name: str,
        access_token: str,
        api_path: str,
    ) -> None:
        """Initialize the class.

        Args:
            org_name (str): The name of the organization.
            repo_name (str): The name of the repository.
            access_token (str): The access token.
            api_path (str): The path to the API.
                Use [BRX/TX] to get a list of all the files in the folder.
        """
        self.logger = self._logger()
        self._processor(
            self._fetcher(
                f'https://api.github.com/repos/{org_name}/{repo_name}/contents',
                self._session(access_token),
                api_path,
            ),
        )

    @staticmethod
    def _logger() -> logging.Logger:
        """Setup the logger."""
        logging.basicConfig(level=logging.INFO)
        return logging.getLogger(__name__)

    @staticmethod
    def _session(access_token: str) -> requests.Session:
        """Setup the session with headers.

        Args:
            access_token (str): The access token.
        """
        session = requests.Session()
        session.headers.update(
            {
                'Authorization': f'token {access_token}',
                'Accept': 'application/vnd.github.v3+json',
            }
        )
        return session

    def _fetcher(
        self,
        base_url: str,
        session: requests.Session,
        path: str = '',
    ) -> dict[str, str] | list[dict[str, str]]:
        """Fetch the contents of the repository.

        Args:
            base_url (str): The base URL.
            session (requests.Session): The session.
            path (str, optional): The path to the contents. Defaults to ''.
        """
        try:
            response = session.get(f'{base_url}/{path}')
            response.raise_for_status()
        except requests.RequestException as e:
            self.logger.error(f'Request failed: {e}')
            raise
        return response.json()

    def _processor(
        self,
        fetcher: dict[str, str] | list[dict[str, str]],
    ) -> None:
        """Process the contents of the repository.

        Args:
            fetcher (dict[str, str] | list[dict[str, str]]):
                The fetcher.
        """
        # NOTE: add 'latest' to the path to get the latest release
        if isinstance(fetcher, dict):
            if fetcher.get('download_url'):
                self.logger.info(fetcher['download_url'])
                temp_path = self._downloader(fetcher['download_url'])
                self._installer(temp_path)
        else:
            for file in fetcher:
                if file.get('download_url'):
                    self.logger.info(file['download_url'])

    def _downloader(self, url: str) -> str:
        """Download the API.

        Args:
            url (str): The URL of the API.
        """
        response = requests.get(url, stream=True)
        response.raise_for_status()

        temp_path = os.path.join(
            tempfile.gettempdir(), os.path.basename(urlparse(url).path)
        )

        with open(temp_path, 'wb') as file:
            for chunk in response.iter_content(chunk_size=8192):
                file.write(chunk)

        self.logger.info(f'Downloaded to: {temp_path}')
        return temp_path

    def _installer(
        self, temp_path: str, install_path: str = os.path.expanduser('~/lib')
    ) -> None:
        """Install the API.

        Args:
            temp_path (str): The temporary path.
            install_path (str, optional): The install path.
                Defaults to os.path.expanduser('~/lib').
        """
        new_dir_path = os.path.join(
            install_path, os.path.splitext(os.path.basename(temp_path))[0]
        )

        os.makedirs(new_dir_path, exist_ok=True)

        with zipfile.ZipFile(temp_path, 'r') as zip_ref:
            zip_ref.extractall(new_dir_path)

        self.logger.info(f'Unzipped files to: {new_dir_path}')

        os.remove(temp_path)

        self.logger.info(f'Removed the zip file: {temp_path}')


SetupAPI(
    org_name='Structura-Engineering',
    repo_name='Bricsys-API',
    access_token=getpass('Please enter your access token: '),
    api_path='BRX/BRXSDK_Bcad_V24_2_03-1.zip',
)
